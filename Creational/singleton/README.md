# Intent

    Ensure a class only has one instance, and provide a global point of access to it

# Structure


                    +-----------------------------+
                    |         Singleton           |
                    +-----------------------------+
                    | static Instance()           |◁────┐
                    +-----------------------------+     │
                    | static uniqueInstance       |     │
                    +-----------------------------+     │
                                                        ▼
                                            +------------------------+
                                            |  return uniqueInstance |
                                            +------------------------+


# Participants
    • Singleton
        - defines an Instance operation that lets clients access its unique instance.
        Instance is a class operation (i,e. a static member function in C++).
        - may b e responsible for creating its own unique instance.
