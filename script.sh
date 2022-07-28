#! /bin/bash
@if test -d /run/WSL; then echo export DISPLAY=$$(cat /etc/resolv.conf | grep nameserver | awk '{print 
	$$2}'):0.0; fi
@if test ! -d /run/WSL; then echo export DISPLAY=localhost:0.0; fi
