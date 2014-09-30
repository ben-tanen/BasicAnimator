## Basic Animator (in C++)

One of my COMP-11 projects was to simulate fish swimming around a fish tank. One of the main principles of the project was to keep the program as modular and abstract as possible. Because of this, I thought it would be pretty simple to gut the [SimFishy project](http://www.google.com) and turn it into a VERY modular basic animator in C++. So the goal of this project is to make a simple animator that can take parameters for a canvas and information for misc. sprites.

#### Current Progress

At the moment, the first step toward the ultimate goal was gutting all of the "fish" and "fishtank" language from the class implementation/interface. At the moment, the project is still built the exact same way but the "fish" are no longer "fish", they're "sprites". More changes to come...

#### To Do

- [ ] Gut SimFishy Language
	- [ ] Actual Code Language
	- [ ] Comments
- [ ] Add Custom Canvas
	- [ ] Custom Frame (based on different size inputs)
	- [ ] Declare wrap-around ability (?)
- [ ] Add ability to specify paths (beyond velocity and position)
- [ ] Add ability for multiple sprite images (multi-animated sprites)
