# 🧮 MatteXKalkulator

Et C++-prosjekt laget for å utforske og implementere sentrale konsepter fra **Matematikk X (MAT02‑02)**.

Prosjektet startet som et enkelt tallteori-verktøy og utviklet seg gradvis til et større matematisk toolkit med:

- Primtall
- Euklids algoritme
- Omvendt Euklids algoritme
- Diofantiske ligninger
- Kongruensregning
- Grunnleggende koordinatgeometri

---

# ✨ Features

## 🔢 Primtallssjekk
Sjekker om et tall er et primtall.

### Eksempel
```text
Input: 17
Output: Ja, 17 er et primtall.
```

---

## 🧩 Primtallsfaktorisering
Faktoriserer et tall til primfaktorer.

### Eksempel
```text
60 = [ 2 2 3 5 ]
```

---

## 📐 Euklids Algoritme
Finner største felles divisor (SFD/GCD).

### Eksempel
```text
SFD av 84 og 30 = 6
```

---

## 🔁 Omvendt Euklids Algoritme
Finner heltallsløsninger til:

ax + by = gcd(a,b)

### Eksempel
```text
84*(-1) + 30*(3) = 6
```

---

## 📏 Diofantiske Ligninger
Løser lineære diofantiske ligninger på formen:

ax + by = c

og returnerer generell løsning.

### Eksempel
```text
x = 4 + 3k
y = -2 - 5k
```

---

## 🌀 Kongruensregning
Sjekker kongruens:

```text
 a ≡ b (mod n)
```

### Eksempel
```text
17 ≡ 5 (mod 12)
```

---

## 📍 Geometri
Prosjektet inneholder også grunnleggende koordinatgeometri:

- Punktstruktur (`Pungt`)
- Avstand mellom punkt
- Linjetester
- Trekanter

### Eksempel
```text
Er punkt P på linja AB?
→ true / false
```

---

# 🛠️ Teknologi

- **Språk:** C++
- **Build system:** CMake
- **Standardbibliotek:** STL

---

# 📂 Prosjektstruktur

```text
MatteXKalkulator/
│
├── include/
│   ├── primtall.hpp
│   ├── euklid.hpp
│   ├── kongruens.hpp
│   ├── geometriskSted.hpp
│   └── ...
│
├── src/
│   ├── primtall.cpp
│   ├── euklid.cpp
│   ├── main.cpp
│   └── ...
│
├── build/
├── CMakeLists.txt
└── README.md
```

---

# 🚀 Build & Run

## Linux / macOS

```bash
mkdir build
cd build
cmake ..
make
./test
```

---

# 🧠 Matematiske konsepter brukt

Dette prosjektet bruker blant annet:

- Rekursjon
- Tallteori
- Modulær aritmetikk
- Geometri
- Vektorer
- Kolinearitet
- Diofantiske ligninger
- Algoritmisk problemløsning

---

# 🔥 Ting prosjektet lærte meg

- Strukturering av større C++-prosjekter
- Header/source-separasjon
- Operator overloading
- Rekursive algoritmer
- Matematisk modellering i kode
- Problemløsing og debugging

---

# 📈 Fremtidige idéer

- Modulær invers
- Fast modular exponentiation
- CRT (Chinese Remainder Theorem)
- Flere geometriske verktøy
- Bedre UI/menysystem
- Inputvalidering

---

# 💀 Fun facts

- Prosjektet gikk fra:

```text
"jeg skal bare lage en primtallsjekk"
```

til:

```text
"mini matematisk toolkit"
```

- Geometrisk sted ble nesten visualisert med matplotlib før det ble erklært “overkill som faen”.

---

# 👑 Status

✅ Aktivt utviklet

✅ Dekker store deler av Matte X-pensum

✅ Har blitt et surprisingly stort prosjekt

---

# 📜 License

MIT-ish.

Hvis du klarer å forstå all koden uten å miste forstanden fortjener du å bruke d