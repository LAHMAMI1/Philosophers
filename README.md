# Philosophers

## Project Overview
This project is an implementation of the classic Dining Philosophers problem in C. It simulates a group of philosophers who alternately think, eat, and sleep while competing for limited forks.

## Theory
The Dining Philosophers problem is a classic concurrency scenario that illustrates issues such as deadlock, starvation, and resource contention. Philosophers alternately think and eat, competing for a limited number of forks, demonstrating the need for proper synchronization.

## Objectives
- Implement thread creation and management using POSIX threads (`pthread`).
- Synchronize access to shared resources (forks) with mutexes.
- Design a strategy to avoid deadlock and ensure all philosophers can eat without starvation.
- Employ precise timing functions to simulate real-world delays in eating and sleeping.

## Learning Outcomes
- Hands-on experience with multithreading concepts and POSIX thread APIs.
- Understanding of synchronization primitives like mutexes and their role in preventing race conditions.
- Techniques for deadlock avoidance and resource allocation strategies.
- Skills in timing and atomic operations for accurate simulation of concurrent behavior.

## Requirements
- Linux or macOS
- `gcc` compiler
- `make`

## Compilation
Use the provided `Makefile` to build the executable:

```bash
make
```
This will produce the `philo` binary.

## Usage
Run the simulation with the following arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: Total philosophers and forks.
- `time_to_die` (ms): Time until a philosopher dies without eating.
- `time_to_eat` (ms): Time a philosopher spends eating.
- `time_to_sleep` (ms): Time a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat` (optional): Simulation stops when each philosopher has eaten this many times.

### Example
```bash
./philo 5 800 200 200
```

## Project Structure
- `philo.c`  — Core simulation and argument parsing.
- `init.c`   — Initialization of philosophers and forks.
- `check_int.c` — Input validation.
- `utils.c`  — Timing and printing helpers.
- `to_do.c`  — Philosophers’ actions (take forks, eat, sleep, think).
- `philo.h`  — Structures and function prototypes.
- `Makefile` — Build rules (`all`, `clean`, `fclean`, `re`).

## Build Targets
- `make` or `make all`: Compile the program.
- `make clean`: Remove object files.
- `make fclean`: Remove object files and executable.
- `make re`: `fclean` then `all`.

## Author
Project developed as part of algorithm and concurrency practice.
