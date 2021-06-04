t = 0:00.1:20;
a = -0.006*t.^3 + 0.19875*t.^2;
b = -0.018*t.^2 + 0.3975*t;
c = -0.036*t + 0.3975;
figure(1);
hold on
plot(t, a, 'r-');
grid();
title('Angular Trajectory q0 -> qv', 'FontSize', 18);
xlabel('time, sec', 'FontSize', 16);
ylabel('Angle, degrees', 'FontSize', 16);
%ylim([-40, 40]);
hold off

figure(2);
hold on
plot(t, b, 'r-');
grid();
title('Angular Trajectory q0 -> qv', 'FontSize', 18);
xlabel('time, sec', 'FontSize', 16);
ylabel('Angular Velocity, degrees/sec', 'FontSize', 16);
%ylim([-40, 40]);
hold off

figure(3);
hold on
plot(t, c, 'r-');
grid();
title('Angular Trajectory q0 -> qv', 'FontSize', 18);
xlabel('time, sec', 'FontSize', 16);
ylabel('Angular Accelaration, degrees/sec^2', 'FontSize', 16);
%ylim([-40, 40]);
hold off