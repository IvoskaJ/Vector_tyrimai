# Vector_tyrimai
Atlikti vektoriaus tyrimai


    Įsitikinkite, kad Jūsų Vector konteineris veikia (funkcionalumo prasme) lygiai taip pat, kaip ir std::vector , t.y. atkartokite visus pavyzdžius pateiktus visoms std::vector konteinerio funkcijoms ir įsitikinkite, kad gaunate tuos pačius rezultatus naudojant Vector objektus. Ataskaitai README faile reiktų aprašyti bent 5 skirtingų funkcijų (operatoriai irgi yra funkcijos) pavyzdžius. P.s. Kol kas leidžiu patiems pasirinkti tas funkcijas, vėliau bus sukonkretintos ir jos tikrai bus tos, kurios yra sudėtingesnės - todėl, kas stengiatės nelaukti "deadline" pabaigos, teoriškai gali pasirinkti paprastesnes funkcijas.
    Atlikite efektyvumo/spartos analizę: originalusis std::vector vs Jūsų Vector. Palyginkite (pateikite ir pakomentuokite README faile lentėles) kiek vidutiniškai laiko užtrunka  std::vector tipo ir Jūsų Vector tipo tuščius vektorius užpildyti: 10000, 100000, 1000000, 10000000 ir 100000000 int elementų naudojant push_back() funkciją:

    // Pradėti v1 užpildymo laiko matavimą
    unsigned int sz = 10000;  // 100000, 1000000, 10000000, 100000000
    std::vector<int> v1;
    for (int i = 1; i <= sz; ++i)
      v1.push_back(i);
     // Baigti v1 užpildymo laiko matavimą

     // Pradėti v2 užpildymo laiko matavimą
    Vector<int> v2;
    for (int i = 1; i <= sz; ++i)
      v2.push_back(i);
    // Baigti v2 užpildymo laiko matavimą

        Palyginkite kiek kartų 2 užduotyje (V2.0) įvyksta konteinerių (Vector ir std::vector) atminties perskirstymai užpildant 100000000 elementų. Perskirstymas įvyksta     tada, kai yra patenkinama sąlyga: capacity() == size(), t.y. kai nelieka vietos capacity()`naujiems elementams.
        Jūsų trečiojo darbo programoje vietoje std::vector panaudokite sukurtą Vector ir įsitikinkite, kad naudojant Vector Jūsų trečiojo darbo programa veikia     teisingai.

        atlikite spartos analizę, t.y. naudojant duomenų failą su 100000 studentų įrašų, palyginkite kiek laiko užtrunka programos veikimas naudojant std::vector ir    Vector realizacijas.
    
    Vektor.push() ir std::vector.push_back() palyginimas:
   ![newVector vs stdVector](https://user-images.githubusercontent.com/78845735/122122208-2c7e5f00-ce35-11eb-9831-68badf3ac0c3.png)
    
    kaip matome klasės Vektor.push() veikia greičiau negu std::vector.push_back()
    
    darbo su studentu failais palyginimas:
    su std::vector: 
    
   ![stdVector](https://user-images.githubusercontent.com/78845735/122122383-664f6580-ce35-11eb-9844-b7610d4d527d.png)
    
    su klase Vektor:
    
   ![newVector](https://user-images.githubusercontent.com/78845735/122122415-71a29100-ce35-11eb-81c5-930890da5df6.png)
  
    Kaip matome klasė Vektor dirba greičiau nei std::vector.
 
