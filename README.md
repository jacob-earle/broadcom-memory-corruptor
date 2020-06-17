# Broadcom Memory Corruptor
This project will provide an alternative driver for Broadcom ethernet controllers that are run by the tg3 driver. This alternative driver will add the capability to corrupt a physical frame in memory and cause cache incoherency by using the ethernet port's DMA controller to copy data to a specified location.

Addtionally, a small c program is provided to lookup the physical frame number corresponding to a virtual page in a given process pagetable.

We can then pass that physical frame number to our kernel module, which will zero out that physical page.

This capability will be used to test whether [this project](https://github.com/jacob-earle/rust-uncrashable-module).
