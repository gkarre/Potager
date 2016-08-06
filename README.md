# Potager
This project is made to create an arduino based system that can monitor and give water to plants in a vegetable garden.
For the moment it is only used to give water to tomatos plants.
It's using an arduino UNO R3 card as the main controler. 
It has 4 lines of hygrometry earth check. Each line is connected to one ANALOG entry of the Arduino ( 2 to 5).
It has also two potentiometers that are plugged to ANALOG entry of the Arduino ( 0 to 1). These are use to set the level of humidity that will start the water pump. As it's using a R3, there are only two potentiometers and each are managing two lines of vegetables. With a MEGA board you can have 4 potentiometers and get more controls.
Pumps are connected on a switch board that has four entry. Entries are connected to the DIGITAL PIN (2 to 5)

Next objectives are:
  - Consume less power when idle
  - Add a system to check the air temperature and humidity. With this control a window on the roof of the greenhouse to have the best temperature for your vegetables.
  - Connect the entire system to a Raspberry Pi and connect it to the openfarm database to control the system based on this database.
  - Create a web interface to be able to manage more type of vegetables.

