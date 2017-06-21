Tutorial

# http://bigdinotech.com/tutorials/galileo-tutorials/using-1-wire-device-with-intel-galileo/

Configure DNS

connmanctl services  # figure out your ethernet device eg. mine was: ethernet_984fee05a892_cable  
connmanctl config ethernet_984fee05a892_cable --nameservers 8.8.8.8 8.8.4.4 #these are Google's nameservers 
