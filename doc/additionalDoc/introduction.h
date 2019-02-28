/**
\page subp_concept_intro General introduction
\section intro_dynamicGraph Introduction

The dynamic-graph package is used to connect computation nodes, "entities"
together using a graph system, akin to what Simulink does. Entities are connected
through input and output signals.
With the building blocks this package provides, you can easily create a full computation graph
for a given problem. It is the basis for the stack of tasks operation.


\subsection controlgraph Exemple: Real-time control

<p>To give a more concrete example, the real-time control used by the Gepetto group for the humanoid robot HRP-2
is detailled.</p>
<p>
Real-time control system are usually driven by a cyclic computational node which
needs to send a control reference value to each motors of a robot. To compute this
control reference values, sensor values need to be provided.
In the Stack-Of-Tasks special entities called Device are used to
provide an abstract interface to the hardware.</p>
A scheme of the real-time control graph used for the humanoid robot HRP-2 is depicted in the following figure:

\image html Concept-Software-Fig.png

You can find an example of a real example of control graph at \ref writegraphdoc.

<p>The device therefore has a specific input which should contain the control vector.
This control vector is the result of a computation solving a control problem.
The entity in charge of solving this control problem is called "Solver" in the previous
figure.
In the SoT framework it is often cast as an optimization problem.
This optimization problem is build using a control "Task" (not to be confused with the
general word task). A control "Task" regulates the difference with a "Feature" computed
on the current robot state and a "Desired Feature". For instance when walking, the regulated
feature is the robot's Center-Of-Mass (CoM) position. The "Feature" is computed using a
library using the robot model and the sensor value. The entity making this computation is "Dyn".
A walking pattern generator using foot-steps position given in advance generates the desired
value for the CoM.
Note that the "Dyn" entity uses the sensor provided by the entity "Robot". </p>

<p>
From a pure computer science viewpoint we wish to avoid recomputing data such as articular Jacobians
when this is unnecessary. Therefore the data generated by an entity through signals may have two types of
dependencies: one dependency related to time and dependencies on other signals. Internally an entity
does not recompute the data if no new information is available, it is simply providing the same information
computed before. Please note that this package provides only the computational framework to realize
the data dependency and the entities. Solvers, libraries to compute mechanical quantities are provided
in different packages.
</p>

<p>
Finally in order to dynamically create a graph, it is possible \b on-line to load classes of entities  and
create instances of entities.</p>

\subsection Functionnalities

\li Support for extensions and modules using dynamic link libraries
\li Template-based signal definition, independent
\li Type-safe connection of input and output signals
\li On-demand signal computation as well as a caching system for signal values allow fast
computation of signal values, which is a critical point for real-time systems\n
See \ref scriptingabout

*/
