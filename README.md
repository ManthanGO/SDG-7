MINI PROJECT
Project Title: Smart Home Energy Grid System (OOP Simulation)
Student & Group Details
•	Group Number: I2
•	Student Name(s): Manthan Goel, Ayush, Sidharth
•	Enrollment Number(s): 03514803125, 04014803125, 03614803125
•	Course / Semester: B.Tech Information Technology / 3rd Semester
•	Subject: Object-Oriented Programming (OOP)
Abstract
This project addresses the inefficiency of domestic energy consumption by proposing an object-oriented simulation of a Smart Home Energy Grid. The core problem is the lack of centralized monitoring for households utilizing a mix of solar power, battery storage, and traditional grid electricity. By leveraging Object-Oriented Programming (OOP) concepts in C++—specifically polymorphism and abstraction—we model different energy consumption behaviors through an 'Appliance' interface. The system simulates the interaction between Solar Panels, Batteries, and the Power Grid to fulfill energy demand dynamically. The final outcome is a scalable software architecture capable of monitoring power usage, switching between power sources efficiently, and optimizing energy flow to prioritize clean energy usage and reduce grid dependency.
Problem Statement
Households lack centralized, intelligent systems to monitor and optimize energy consumption across various appliances while seamlessly managing multiple power sources (e.g., solar, battery, and main grid). This leads to energy wastage, higher carbon footprints, and increased electricity bills.
Objectives
•	Objective 1: Model real-world household energy consumption utilizing OOP concepts like abstraction, inheritance, and encapsulation.
•	Objective 2: Implement polymorphism to handle and calculate the distinct energy consumption behaviors of various household appliances (e.g., Heavy vs. Light loads).
•	Objective 3: Simulate an intelligent energy routing system that prioritizes renewable Solar Power and Battery storage before drawing from the main Power Grid.
Methodology / Approach
•	Tools/Technologies used: C++ (Core OOP), VS Code, Git/GitHub for version control.
•	Steps followed:
•	1. Requirement Analysis: Mapped system components to SDG 7 goals.
•	2. Class Design: Designed core classes (Appliance, SolarPanel, Battery, PowerGrid, SmartGrid).
•	3. Abstraction & Polymorphism: Created an Appliance interface and overrode consumption methods for different appliance types.
•	4. Integration & Logic: Built the SmartGrid manager class to evaluate available power and allocate it prioritizing renewable sources.
Implementation & Output
•	Key features of our system:
•	Polymorphic Energy Calculation: Automatically calculates total load by treating all devices as 'Appliance' objects.
•	Dynamic Power Switching: Logic to draw from SolarPanel first, fallback to Battery, and finally utilize the PowerGrid.
•	State Tracking: Real-time tracking of object states (e.g., remaining Battery capacity, solar output, billable grid usage).
•	Add small screenshots:
[Insert the screenshot of your VS Code / C++ console output here showing the energy allocation]
Results
•	What we achieved: Successfully modeled energy flow and calculated total power consumption dynamically based on appliance states using a modular C++ architecture.
•	Performance / accuracy: Demonstrated a simulated 100% utilization of available renewable energy (Solar/Battery) before defaulting to the standard grid, proving the efficiency and accuracy of the prioritization logic.
Conclusion
•	Learning outcomes: Gained practical experience applying core OOP principles (polymorphism, abstraction, inheritance) to a real-world software architecture problem.
•	Summary of the work: Developed a modular, extensible OOP architecture for a smart home energy grid that effectively tracks and manages power consumption across various components to support sustainable energy.
Future Scope
•	Possible improvements:
•	Integrate with real IoT sensor data and APIs for live power tracking.
•	Develop a Graphical User Interface (GUI) or web dashboard to replace the console-based output.
•	Add machine learning algorithms to predict peak consumption hours.
Mapped SDG
•	SDG 7: Affordable and Clean Energy
