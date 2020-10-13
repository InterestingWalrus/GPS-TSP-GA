# GPS-TSP-GA

A program used to solve the best route given a set of GPS waypoints. Written using QT framework and using the `QGeoCoordinate` class for GPS waypoints. Intended to be used by a drone so program assumes "as crow flies" to generate distances between waypoints. largely based on the TSP series on Youtube by TheCodingTrain

# Usage

- Declare an Object of `GpsClass`
- Create a vector of `QGeoCoordinate` points
- Set maximum number of iterations
- Call `computeFitness()`, `normalizeFitness` and `nextGeneration`

Example usage can be found in `main.cpp`. Documentation is shown in the *doc* folder.

# ToDo
 - Remove Max number of generations and stop once you reach convergence.

 