% N read write time

linear = [2^8 160 1 0.042283058166 ;
2^9 606 1 0.117465972 ;
2^10 2099 1 0.40456008911 ;
2^11 9273 1 1.7546510696 ;
2^12 36027 1 6.8179030418 ;
2^13 138373 1 27.337857961 ;
2^14 564154 1 116.01909589 ;
2^15 2166013 1 459.72247910 ;
2^16 8476367 1 1822.8984458 ;
2^17 34024964 1 7443.4412531
	];

  
greene = [2^8 126 1 0.027206897735 ;
2^9 413 1 0.09287595748 ;
2^10 1245 1 0.26709794998 ;
2^11 5235 1 1.0269429683 ;
2^12 22692 1 4.4845519065 ;
2^13 89385 1 17.886777877 ;
2^14 333829 1 66.499850034 ;
2^15 1278953 1 273.49097800 ;
2^16 4641438 1 1013.0755629 ;
2^17 17975993 1 3861.4914810
];

plot(linear(:,1),linear(:,2)./linear(:,1)./log2(linear(:,1)),'*-b','linewidth',2);
hold on
plot(greene(:,1),greene(:,2)./greene(:,1)./log2(greene(:,1)),'*-r','linewidth',2);
hold off
xlabel('Cantidad de busquedas (N)');
ylabel('Lecturas / N log N');
title('Lecturas en busqueda en RTree')
axis([0 2^17 0 16]);
legend('Linear','Greene','location','northwest');
grid on;
print -depsc nlogn.eps