Простая модель лёгких человека для подсчёта радиационной дозы, полученной при флюорографии/рентгенографии.
При создании был использован exampleB1, изменены только генератор частиц и конструкция детектора.
Для итогового подсчета следует выполнить моделирование на энергиях от 20 keV до 100 keV, и полученные результаты подставить в формулу:
$$\sum_{E=20}^{100} hqUp(E)rez(E)/NE$$ где N - количество запусков, а p(E) - спектральная плотность.
При работе были использованы некоторые допущения:\
-Заряд, прошедший через рентгеновскую трубку: q = 0.1 mA*c\
-Напряжение на ней: U = 90 kV;\
-КПД трубки: h = 1%\
-Угол раствора рабочего пучка излучения - 70 deg\
-Расстояние от центра "легких" до излучателя - 0.6 m
