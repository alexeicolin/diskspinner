diskspinner
===========

Silly little utility that keeps disks spinning in order to work around bugs
in USB-to-SATA bridges that fail when the harddrive goes into idle mode.

One such unsavory combination turns out to be WD drives with DatOptic U3eSATA
dongle. Other than the disconnect-on-idle problem the dongle works fine.

Usage
-----

Install:

    cp diskspinner@.service /usr/lib/systemd/system
    cp diskspinner /usr/bin/

Configure to start automatically on boot:

    systemctl enable diskspinner@sdX
