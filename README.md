# prRobotics

*В этом репозитории содержатся файлы курсового проекта (КП) по программированию роботов!*
Выполнили КП: Захаров и Макаренко
# Тема КП: ROS-Navigation stack
***
ROS-Navigation stack направлен на поиски безопасного перемещения мобильного робота из одной точки в другую или может использоваться для следования за динамическими точками. Такой мобильный робот должен быть оборудован датчиками и управляться системой ROS.Моделирование происходит в симуляторе Gazebo и с помощью робота TurtleBot:
![image](https://user-images.githubusercontent.com/122403116/214343443-d7599a2e-379f-490e-a7a8-3dc8d3e9aa3a.png)

Порядок запуска проекта:
- Создание черепашьего мира:
$ roslaunch turtlebot3_gazebo turtlebot3_world.launch
- Запуск узла SLAM:
$ roslaunch turtlebot3_slam turtlebot3_slam.launch slam_methods:=gmapping
- Запуск узла навигации:
$ roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=$HOME/map.yaml
- Запуск файла с координатами:






