#include "sync_car.h"

void station_init(struct station *s)
{
	pthread_mutex_init(&s->lock, NULL);
	pthread_cond_init(&s->arrived, NULL);
	pthread_cond_init(&s->done, NULL);
	s->waiting = 0;
	s->seats = 0;
	s->boarding = 0;
	s->open = 0;
}

void station_load_car(struct station *s, int count)
{
	pthread_mutex_lock(&s->lock);
	if (count <= 0 || s->waiting == 0) {
		pthread_mutex_unlock(&s->lock);
		return;
	}
	s->seats = count;
	s->open = 1;
	pthread_cond_broadcast(&s->arrived);
	while (s->boarding > 0 || (s->waiting > 0 && s->seats > 0))
		pthread_cond_wait(&s->done, &s->lock);
	s->open = 0;
	s->seats = 0;
	pthread_mutex_unlock(&s->lock);
}

void station_wait_for_car(struct station *s)
{
	pthread_mutex_lock(&s->lock);
	s->waiting++;
	while (!s->open || s->seats == 0)
		pthread_cond_wait(&s->arrived, &s->lock);
	s->waiting--;
	s->seats--;
	s->boarding++;
	pthread_mutex_unlock(&s->lock);
}

void station_on_board(struct station *s)
{
	pthread_mutex_lock(&s->lock);
	s->boarding--;
	if (s->boarding == 0)
		pthread_cond_signal(&s->done);
	pthread_mutex_unlock(&s->lock);
}