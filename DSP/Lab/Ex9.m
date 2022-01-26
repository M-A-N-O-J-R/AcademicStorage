%FIR filter order 21, w=0.1, cutoff frequency=5Hz, Sampling frequency = 100Hz
b = fir1(21,0.1);freqz(b,1,512);
%IIR filter order 5, w=0.1, cutoff frequency=5Hz, Sampling frequency = 100Hz
fc=5;
fs=100;
figure;
w=0:.001:pi;
[Bl1,Al1]=butter(5,((2*fc)/fs));
p3=freqz(Bl1,Al1,w);
subplot(2,1,1);
plot((w/pi),abs(p3));
title('butterworth lpf magnitude response');
xlabel('normalized freq');
ylabel('amplitude');
subplot(2,1,2);
plot((w/pi),phase(p3));
title('butterworth lpf phase response');
xlabel('normalized freq');
ylabel('phase');
