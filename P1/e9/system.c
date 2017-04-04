int system (const char *cmd){
	if( fork() == 0){
		exec("/bin/bash", cmd);
	}
	else{
		wait();
	}
}