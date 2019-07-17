rem ***********************************************************
rem       ARM Debug Initial File
rem        Copyright 1999-2004, Jedi Systems Inc.,
rem         
rem ***********************************************************
rem ***SDRAM_Little_16***
!
rem BWSCON
LONG 0x1c80000  0x11110102
	
rem GCS0
LONG 0x1c80004  0X600	

rem GCS1
LONG 0x1c80008  0X7FFC	

rem GCS2
rem LONG 0x1c8000c  0X7FFC	

rem GCS3
rem LONG 0x1c80010  0X7FFC
		
rem GCS4
rem LONG 0x1c80014  0X7FFC
		
rem GCS5
rem LONG 0x1c80018  0X7FFC	
	
rem GCS6 EDO DRAM(Trcd=3,Tcas=2,Tcp=1,CAN=10)
rem LONG 0x1c8001c  0X1002a	

rem GCS6 SDRAM(Trcd=2,SCAN=8)
LONG 0x1c8001c  0X18000	
	
rem GCS7 EDO DRAM(Trcd=3,Tcas=2,Tcp=1,CAN=10)
rem LONG 0x1c80020  0X1002a
	
rem GCS7 SDRAM(Trcd=2,SCAN=8)
LONG 0x1c80020  0X18000		

rem Refresh(REFEN=1,TREFMD=0,Trp=3.5(D)or 4(SD),Trc=5(S), Tchr=3(D),Ref CNT)
rem LONG 0x1c80024  0x820591   £¿£¿£¿£¿
LONG 0x1c80024 0x00860459

rem Bank size, 8MB/8MB
rem LONG 0x1c80028  0x16    £¿£¿£¿£¿
LONG 0x1c80028 0x00000010
	
rem MRSR 6(CL=2)
LONG 0x1c8002c  0x20	
	
rem MRSR 7(CL=2)
LONG 0x1c80030  0x20
	
rem MCLK=40M
LONG 0x1d80000  0x48032	

rem disable WDT
LONG 0X1D30000 0X0

rem all interrupt disable
rem LONG 0x1e0000c 0x07ffffff

rem write buffer has to be off for proper timing.  
LONG 0x1c00000 0x0

rem flash area(Bank0) must be non-cachable area.
rem LONG 0x1c00004 0x20000000

!
