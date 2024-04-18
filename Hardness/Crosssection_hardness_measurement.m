clear all
close all

%%Parameters

r = 2.65;
h = r - 1.5;

%% Formula

A_circle = r^2*pi;
A_sequement = r^2*acos(1-(h/r))-(r-h)*sqrt(2*r*h-h^2);

A_ref = A_circle - 2*A_sequement