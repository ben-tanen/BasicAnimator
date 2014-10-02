## Basic Animator

This is a simple ASCII Sprite animator written in C++. The ultimate goal is that it can read-in multiple sprites (which may have multiple images) and animate them using set velocities or set paths. The project itself is based on the COMP-11 project 'SimFishy' (see the ben-tanen/Tufts repo for more).

#### Current Progress

After re-working 'SimFishy' project, I've decided to start from scratch. Currently working on the basic animObject class...

#### To Do

- [ ] Multi-Sprite animObject
	- [x] Create class base (parameters)
	- [x] Class basics (constructor)
	- [ ] Object `readIn()`
	- [ ] Animate and draw functions
- [ ] Add Custom Canvas
	- [ ] Custom Frame (based on different size inputs)
	- [ ] Declare wrap-around ability (?)
- [ ] animObject Movement
	- [ ] Specify object movement with path or initial position and velocity
	- [ ] Path Integration
		- [ ] TBD...
	- [ ] Initial Velocity / Position
		- [ ] TBD...
- [ ] Multi-Object Support
