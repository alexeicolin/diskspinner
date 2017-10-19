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

Install the systemd service (optionally edit the interval in the file):

    sudo cp diskspinner@.service /etc/systemd/system/
    sudo systemctl daemon-reload

Then to start the service at boot for each disk mounted at /mnt/xxx:

    sudo systemctl start diskspinner@xxx
    sudo systemctl enable diskspinner@xxx
