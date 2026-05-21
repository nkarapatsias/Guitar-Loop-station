# Custom Mobius 3 Looper Pedalboard

This repository documents a personal hardware and software project to build a custom, professional-grade guitar looper pedalboard. Powered by a **Raspberry Pi Pico W** using the **Arduino framework**, this pedalboard is designed to work seamlessly with **Mobius 3**, a powerful looping plugin hosted inside the **Reaper DAW**. 

Going beyond a simple prototype, this project involves designing a **custom PCB** and wiring all internal circuits from scratch, complete with heavy-duty foot switches and responsive RGB LEDs for precise visual feedback during live performances.

## 🎸 Core Modes of Operation

The pedalboard features three primary modes, giving the performer complete control over their loops:

*   **🔴 Record Mode**
    Enables you to record and overdub multiple layers across different tracks independently. It's ideal for capturing guitar parts, vocals, or other instruments in a flexible, creative workflow.
*   **🟢 Play Mode**
    Controls the playback of your recorded loops. Each track can be muted or unmuted individually, allowing for dynamic live performances and complex, evolving arrangements.
*   **🟡 Stop Mode** 
    Integrated directly into Play Mode, Stop Mode allows you to instantly mute all tracks at once and selectively unmute only the ones you wish to hear. It offers a quick and intuitive way to reset or dramatically shift the arrangement on the fly.

## ⚙️ Features & Customization

*   **Dynamic Routing:** Select which input(s) are routed to each track to fit your specific instrument setup.
*   **DAW Synchronization:** The system stays tightly synced with Reaper's host metronome, ensuring all loops and overdubs remain perfectly rhythmically aligned.
*   **Visual Feedback:** Custom-wired RGB LEDs provide instant, color-coded status updates for each track (e.g., Red for recording, Green for playing, dimmed for muted).
*   **Custom Hardware:** Built from the ground up with a custom-designed PCB, tactile foot switches, and the Pico W serving as the core brain.

## 🚀 Future Roadmap

Because the Raspberry Pi Pico W features built-in Wi-Fi capabilities, the next major phase of this project includes:

*   **📱 Companion Mobile App:** Developing a mobile application to remotely control Mobius 3 *through* the pedalboard's wireless connection. This will allow for wire-free configuration, preset switching, and live-set management directly from a smartphone or tablet.

---

*This project demonstrates how affordable, modern microcontrollers and custom hardware design can be combined with professional audio software to create a highly capable and personalized looping solution for musicians.*
