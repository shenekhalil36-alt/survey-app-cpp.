#include <iostream>
#include <string>

// The entire HTML, CSS, JavaScript, and PWA frontend embedded right inside C++!
const std::string EMBEDDED_WEBSITE = R"raw(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>EarnSurveys PWA</title>
  
  <style>
    * {
      box-sizing: border-box;
      margin: 0;
      padding: 0;
      font-family: system-ui, -apple-system, sans-serif;
    }

    body {
      background-color: #0f172a;
      color: #f8fafc;
      display: flex;
      justify-content: center;
      align-items: center;
      min-height: 100vh;
      padding: 20px;
    }

    .app-card {
      background: #1e293b;
      width: 100%;
      max-width: 400px;
      border-radius: 16px;
      padding: 24px;
      border: 1px solid #334155;
      text-align: center;
      box-shadow: 0 10px 25px rgba(0,0,0,0.5);
    }

    .header h1 {
      font-size: 1.5rem;
      margin-bottom: 4px;
    }

    .header p {
      font-size: 0.85rem;
      color: #94a3b8;
      margin-bottom: 20px;
    }

    .balance-box {
      background: linear-gradient(135deg, #059669, #10b981);
      border-radius: 12px;
      padding: 20px;
      margin-bottom: 20px;
    }

    .balance-amount {
      font-size: 2.5rem;
      font-weight: 800;
      color: #fff;
      margin-top: 4px;
    }

    .survey-box {
      background: #0f172a;
      border: 1px solid #334155;
      border-radius: 12px;
      padding: 16px;
      margin-bottom: 20px;
    }

    .timer {
      font-size: 1.5rem;
      font-weight: 700;
      color: #f59e0b;
      margin: 8px 0;
    }

    .status-text {
      font-size: 0.9rem;
      color: #94a3b8;
    }

    .btn {
      width: 100%;
      background-color: #10b981;
      color: #0f172a;
      font-size: 1rem;
      font-weight: 700;
      padding: 14px;
      border: none;
      border-radius: 10px;
      cursor: pointer;
    }

    .btn:disabled {
      background-color: #334155;
      color: #64748b;
      cursor: not-allowed;
    }
  </style>
</head>
<body>

  <div class="app-card">
    <div class="header">
      <h1>SurveyRewards</h1>
      <p>C++ Embedded PWA Edition</p>
    </div>

    <div class="balance-box">
      <div style="font-size: 0.85rem; text-transform: uppercase; color: #d1fae5;">Total Balance</div>
      <div class="balance-amount" id="balanceDisplay">£0.00</div>
    </div>

    <div class="survey-box">
      <div class="status-text" id="statusTitle">Next Survey Available In:</div>
      <div class="timer" id="timerDisplay">00:00:00</div>
      <div class="status-text">1-hour cooldown active</div>
    </div>

    <button class="btn" id="takeSurveyBtn" disabled>Start Survey (£1.00)</button>
  </div>

  <script>
    const COOLDOWN_MS = 60 * 60 * 1000; // 1 Hour
    const REWARD = 1.00;

    let balance = parseFloat(localStorage.getItem('cpp_balance')) || 0.00;
    let nextTime = parseInt(localStorage.getItem('cpp_next_time')) || 0;

    const balanceDisplay = document.getElementById('balanceDisplay');
    const timerDisplay = document.getElementById('timerDisplay');
    const takeSurveyBtn = document.getElementById('takeSurveyBtn');
    const statusTitle = document.getElementById('statusTitle');

    function updateUI() {
      balanceDisplay.textContent = `£${balance.toFixed(2)}`;
      
      let now = Date.now();
      let timeLeft = nextTime - now;

      if (timeLeft <= 0) {
        timerDisplay.textContent = "READY!";
        timerDisplay.style.color = "#10b981";
        statusTitle.textContent = "New Survey Unlocked!";
        takeSurveyBtn.disabled = false;
      } else {
        takeSurveyBtn.disabled = true;
        timerDisplay.style.color = "#f59e0b";
        statusTitle.textContent = "Next Survey Available In:";

        let totalSecs = Math.floor(timeLeft / 1000);
        let h = Math.floor(totalSecs / 3600);
        let m = Math.floor((totalSecs % 3600) / 60);
        let s = totalSecs % 60;

        let pad = (n) => String(n).padStart(2, '0');
        timerDisplay.textContent = `${pad(h)}:${pad(m)}:${pad(s)}`;
      }
    }

    takeSurveyBtn.addEventListener('click', () => {
      balance += REWARD;
      localStorage.setItem('cpp_balance', balance.toString());

      nextTime = Date.now() + COOLDOWN_MS;
      localStorage.setItem('cpp_next_time', nextTime.toString());

      updateUI();
      alert("Survey completed! £1.00 added.");
    });

    updateUI();
    setInterval(updateUI, 1000);
  </script>
</body>
</html>
)raw";

int main() {
    std::cout << "===========================================" << std::endl;
    std::cout << "      C++ ALL-IN-ONE SERVER CONTAINER      " << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "HTML, CSS, and JS payload compiled successfully." << std::endl;
    std::cout << "Total website string size: " << EMBEDDED_WEBSITE.length() << " bytes." << std::endl;
    std::cout << "\nStatus: Ready for deployment." << std::endl;
    
    return 0;
}

