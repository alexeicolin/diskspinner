diskspinner
===========

Silly little utility that keeps disks spinning in order to work around bugs
in USB-to-SATA bridges that fail when the harddrive goes into idle mode.

One such unsavory combination turns out to be WD40FX drive with DatOptic
U3eSATA dongle. Other than the disconnect-on-idle problem the dongle works
fine.

The utility creates a file of a few MB in disk's mount directory and writes to the disk every 10 seconds.

Usage
-----

Optionally, edit diskspinner@.service to select the interval and filename.

Build and install the binary and the systemd service:

    make
    sudo make install
    sudo systemctl daemon-reload

Then to start the service for each disk mounted at /mnt/xxx:

    sudo systemctl start diskspinner@xxx

To autostart at boot:

    sudo systemctl enable diskspinner@xxx

To uninstall:

    sudo systemctl stop diskspinner@xxx
    sudo systemctl disable diskspinner@xxx
    sudo make uninstall
