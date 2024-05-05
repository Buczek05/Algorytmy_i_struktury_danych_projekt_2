# Projekt sortowanie

## Cel Projektu
Celem projektu jest implementacja, testowanie i porównanie różnych metod sortowania tablic liczb całkowitych

## Metody Sortowania
Metody sortowania zostały podzielone na dwie grupy:

### I Grupa Metod
1. Sortowanie przez wstawianie
2. Sortowanie przez selekcję
3. Sortowanie bąbelkowe

### II Grupa Metod
1. Quicksort
2. Sortowanie Shella
3. Sortowanie przez kopcowanie

## Poniżej przedstawiam diagramy dla każdej z nich

### Sortowanie przez wstawianie
  ![Sortowanie przez wstawianie](diagrams/insert_sort.drawio.svg)
### Sortowanie przez selekcję
  ![Sortowanie przez selekcję](diagrams/select_sort.drawio.svg)
### Sortowanie bąbelkowe
  ![Sortowanie bąbelkowe](diagrams/bubble_sort.drawio.svg)
### Quicksort
  ![Quicksort](diagrams/quick_sort.drawio.svg)
### Sortowanie Shella
  ![Sortowanie Shella](diagrams/shell_sort.drawio.svg)
### Sortowanie przez kopcowanie
  ![Sortowanie przez kopcowanie](diagrams/heap_sort.drawio.svg)

## Testy Wydajności
Dla każdej z metod przeprowadzone zostaną trzy rodzaje testów na tablicach o rosnącej liczbie elementów:

- **Test1:** Dla danych wygenerowanych losowo
- **Test2:** Dla danych posortowanych w kolejności odwrotnej (malejąco)
- **Test3:** Dla danych posortowanych właściwie (rosnąco)

### Pomiar Czasu
Do pomiaru czasu użyta została funkcja systemowa `clock_gettime`, wywoływana przed i po sortowaniu. Różnica uzyskanych czasów wskaże czas sortowania.

## Wykresy Zależności Czasu Sortowania
Dla analizy wyników każdego testu przygotowałem wykresy, gdzie linia kreskowana pokazuje złożoność obliczeniową, a ciągła realny czas:

### Zbiorczy wykres dla metod z I grupy.
<div style="display:flex; justify-content: space-between;">

![Test 1 Grupa 1](result/test_1-group_1.jpg)

![Test 2 Grupa 1](result/test_2-group_1.jpg)

![Test 3 Grupa 1](result/test_3-group_1.jpg)

</div>

### Zbiorczy wykres dla metod z II grupy.
<div style="display:flex; justify-content: space-between;">

![Test 1 Grupa 2](result/test_1-group_2.jpg)

![Test 2 Grupa 2](result/test_2-group_2.jpg)

![Test 3 Grupa 2](result/test_3-group_2.jpg)

</div>

### Zbiorczy porównujący wszystkie metody z I i II grupy.
<div style="display:flex; justify-content: space-between;">

![Test 1 Obie grupy](result/test_1-both.jpg)

![Test 2 Obie grupy](result/test_2-both.jpg)

![Test 3 Obie grupy](result/test_3-both.jpg)

</div>

W sumie uzyskamy 9 wykresów – po 3 dla każdego zestawu danych.
