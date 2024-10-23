# Pipex: Mastering the Art of Pipes 🛠️

## Project Overview 📄

**Pipex** is a crucial project in the 42 school curriculum, introducing us to key Unix concepts such as processes, pipes, and command execution. 
It simulates a shell pipeline, where commands are chained together using pipes to pass the output of one command as input to another. 

This project was particularly important to me because it lays the foundation for **"Minishell"**  🐚, one of the largest projects in the common core.

## Technologies Used 💻

<img src="https://cdn.worldvectorlogo.com/logos/c-1.svg" alt="C" width="40" height="40"/>

## How It Works 🛠️

*Since the bonus part builds upon and expands the mandatory part, I'll demonstrate how to use the bonus functionality.*  

The program replicates the behavior of the following shell command: `infile cmd1 | cmd2 | cmd3 ... | cmdn > outfile`
1. Compile the program with `Make bonus`

2. Run the program with:
3. ```
   ./pipex infile [cmd1] [cmd2] [cmd3] ... [cmdn] outfile  
You can also use a here doc instead of the infile, like the following shell command: `cmd1 << LIMITER | cmd2 >> outfile`   
   ```
   ./pipex here_doc LIMITER cmd1 cmd2 outfile  
   ```
## Challenges Faced 💥

- **Pipe Management**: Managing file descriptors and ensuring proper redirection between commands took careful planning, especially in the bonus part with multiple pipes.
- **Error Handling**: Handling errors robustly was key to avoiding crashes, memory leaks, or undefined behavior. The project required me to implement checks for invalid commands, missing files, and other edge cases. 🚫
- **Memory Leaks**: Preventing memory leaks when dynamically allocating memory during command parsing and execution was very important.

## What I Learned 🧠
This project introduced me to many essential concepts that prepared me for Minishell, one of the biggest projects in the 42 curriculum:
- **Processes and Pipes**: How to work with multiple processes and chain them using pipes. 🔗
- **System Calls**: I became comfortable with system calls like fork, execve, pipe, and dup2, which are crucial for process management and inter-process communication.
- **File Descriptors**: The importance of managing file descriptors and how to duplicate them with dup2 to redirect input/output correctly. 📂
- **Error Handling**: I gained experience in writing robust error-handling routines to manage invalid inputs and system call failures.

