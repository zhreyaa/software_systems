#MT2023179 SHREYA CHAVAN

#Question : 19

#Create a FIFO file by
#a. mknod command
#b. mkfifo command
#c. use strace command to find out, which command (mknod or mkfifo) is better.
#d mknod system call
#e. mkfifo library function

#Date: 1st September, 2023.

#!/bin/bash

# Define the FIFO file name
fifo_name="myfifo"

# Create a FIFO file using mknod
echo "Creating FIFO using mknod..."
if mknod "$fifo_name" p; then
    echo "FIFO created successfully using mknod."
else
    echo "Failed to create FIFO using mknod."
    exit 1
fi

# Use strace to trace mknod
echo "Tracing mknod..."
strace -o mknod_trace.txt mknod "$fifo_name" p
echo "mknod traced. Output saved in mknod_trace.txt."

# Remove the FIFO file created using mknod
rm "$fifo_name"

# Create a FIFO file using mkfifo
echo "Creating FIFO using mkfifo..."
if mkfifo "$fifo_name"; then
    echo "FIFO created successfully using mkfifo."
else
    echo "Failed to create FIFO using mkfifo."
    exit 1
fi

# Use strace to trace mkfifo
echo "Tracing mkfifo..."
strace -o mkfifo_trace.txt mkfifo "$fifo_name"
echo "mkfifo traced. Output saved in mkfifo_trace.txt."

# Remove the FIFO file created using mkfifo
rm "$fifo_name"

# Compare the trace results
echo "Comparing trace results..."
if diff mknod_trace.txt mkfifo_trace.txt >/dev/null; then
    echo "mknod and mkfifo produced the same trace output."
else
    echo "mknod and mkfifo produced different trace output."
fi

# Clean up trace files
rm mknod_trace.txt mkfifo_trace.txt

echo "Script finished."

