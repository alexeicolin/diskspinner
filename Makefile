diskspinner: main.c
	gcc -o $@ $^

clean:
	rm -f diskspinner

install: diskspinner
	install -m755 $^ /usr/local/bin/$^
	install diskspinner@.service /etc/systemd/system/diskspinner@.service

uninstall:
	rm -r /usr/local/bin/diskspinner
	rm -f /etc/systemd/system/diskspinner@.service
