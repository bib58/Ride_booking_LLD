---

# Ride Management System

This project is a simplified ride-booking platform implemented in C++, demonstrating good software design principles, especially SOLID and various design patterns.

---

## 📦 Project Structure

```
ride/
├── FareCalculator.hpp
├── main.cpp
├── NotificationService.hpp
├── pay.hpp
├── Ride.hpp
├── RideManager.hpp
├── Strategy.hpp
└── User.hpp
```

---

## ✅ SOLID Principles Applied

### 1. **Single Responsibility Principle (SRP)**


* `FareCalculator`, `BaseFareCalculator`, `SurgeFareCalculator` – handle fare logic.
* `Notifier`, `CustomerNotifier`, `DriverNotifier` – handle user notifications.
* `PaymentStrategy`, `UpiPayment`, `CashPayment` – handle payment processing.
* `RideManager` – orchestrates ride lifecycle.
* `Ride` – encapsulates a single ride's state.

### 2. **Open/Closed Principle (OCP)**

* `FareCalculator` and `PaymentStrategy` use abstract base classes, allowing extension via new strategies without modifying existing code.
* `MatchingStrategy` makes it easy to add new driver-matching algorithms.

### 3. **Liskov Substitution Principle (LSP)**

* Derived classes (`BaseFareCalculator`, `SurgeFareCalculator`, `UpiPayment`, etc.) can replace their base classes without altering system behavior.

### 4. **Dependency Inversion Principle (DIP)**

* High-level modules like `RideManager` depend on `Ride` and abstractions like `MatchingStrategy` and `FareCalculator`.

---

###  **singleton Design Pattern**

* Used this into Driver finding Strategy between nearest and best rated
---

## ⚖️ Assumptions and Simplifications

* **Surge Pricing**: Used system time clock to decide whether apply surge pricing or base pricing.
* **No persistent storage**: All data is held in memory for the session duration.
* **Simplified Location system**: Used a coordinate grid instead of real maps.

---

## 💡 How to Run

1. Compile using a C++ compiler:
2. Follow console prompts to simulate a ride request.

---
