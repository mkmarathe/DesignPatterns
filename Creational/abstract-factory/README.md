# Intent

    Provide an interface for creating families of related or dependent objects without specifying their concrete classes

# Structure 

    Abstract Factory: An interface or abstract class defining methods to create abstract products.
    Concrete Factory: Implements the abstract factory to create specific product families.
    Abstract Product: Interfaces or abstract classes for the objects being created.
    Concrete Product: Specific implementations of the abstract products.
    Client: Uses the abstract factory and abstract product interfaces to work with objects without knowing their concrete types.
 
<div style="padding-left: 40px;">
  <img src="image.png" alt="alt text" />
</div>

# Participants
    • AbstractFactory (UIFactory)
        - declares an interface for operations that create abstract product objects.
    • ConcreteFactory (WinUI, MacUI)
        - implements the operations to create concrete product objects.
    • AbstractProduct (button, scrollBar)
        - declares an interfacefor a type of product object.
    • ConcreteProduct (winButton, macButton, winScrollBar, macScrollBar)
        - defines a product objecttobecreated bythe corresponding concrete factory.
        - implements the AbstractProduct interface.
    • Client
        - uses only interfaces declared by AbstractFactory and AbstractProduct classes.
    
