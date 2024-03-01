void* start(void *p) {
	pthread_detach(pthread_self());
	return NULL;
}
