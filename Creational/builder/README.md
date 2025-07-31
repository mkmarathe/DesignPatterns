# Intent
        Separate the construction of a complex object from its representation so that the
    same construction process can create different representations.

# Structure
  <div style="padding-left: 40px;">
    <img src="image.png" alt="alt text" />
  </div>

# Participants
- **Builder** (`VehicleBuilder`)
  - Specifies an abstract interface for creating parts of a Product object.
- **ConcreteBuilder** (`SUVBuilder`, `TruckBuilder`)
  - Constructs and assembles parts of the product by implementing the Builder interface.
  - Defines and keeps track of the representation it creates.
- **Director** (`Director`)
  - Constructs an object using the Builder interface.
- **Product** (`SUV`, `Truck`)
  - Represents the complex object under construction. The `ConcreteBuilder` builds the product's internal representation and defines the process by which it's assembled.
    - Includes classes that define the constituent parts, as well as interfaces for assembling these parts into the final result.

  **Note:**  
  > Why is there no abstract class for products? In most cases, the products produced by the concrete builders differ so greatly in their representation that there is little to gain from giving different products a common parent class.
 
  > Empty methods as defaults in `Builder`: The Build methods are intentionally not declared as pure virtual member functions. They're defined as empty methods instead, allowing clients to override only the operations they're interested in.
