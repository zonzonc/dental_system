# dental_system 牙醫掛號管理系統

這是一套以 **C 語言實作的牙醫診所掛號與管理系統**，模擬真實掛號流程與病人資料查詢，並結合多種資料結構如最小堆、AVL 樹、雙向鏈結串列與雜湊表，適合作為資料結構實作與系統整合的學習專題。

---

## 功能特色

-  **病人掛號登記**（支援急診 / 一般分類）
-  **醫生排班管理**（以圖結構模擬）
-  **候診清單管理**（以最小堆依照順序與急迫性排序）
-  **依健保卡號快速查詢病人**（使用 AVL Tree）
-  **繳費與資料紀錄查詢**（雜湊表 Dictionary）
-  **取消掛號管理清單**

---

##  專案結構

```               

dental_system/
├── src/                      
│   ├── patient.c/h           
│   ├── heap.c/h              
│   ├── avl.c/h               
│   ├── dll.c/h               
│   ├── queue.c/h             
│   ├── dictionary.c/h        
│   ├── graph.c/h             
│   ├── cancellationlist.h    
│   ├── main.c                
│   └── Makefile              
└── dental_system.xcodeproj/  

```               
