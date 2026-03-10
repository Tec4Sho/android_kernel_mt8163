#include <linux/kernel.h>
#include <linux/sched.h>

/* Scheduler Stubs */
void update_sched_hint(void) {}
void inc_nr_heavy_running(void *cfs_rq) {}
void dec_nr_heavy_running(void *cfs_rq) {}
void sched_update_nr_prod(int cpu, int delta, bool rt) {}
void sched_max_util_task_tracking(void) {}
int sched_get_percpu_load(int cpu) { return 0; }
int sched_get_nr_heavy_task(int cpu) { return 0; }
unsigned long sched_get_nr_running_avg(int cpu) { return 0; }

/* Power/Thermal Stubs */
void mt_ptp_lock(void) {}
void mt_ptp_unlock(void) {}
int tscpu_get_temp_by_bank(int bank) { return 0; }
void tscpu_cancel_thermal_timer(void) {}
void tscpu_start_thermal_timer(void) {}
int get_thermal_slope_intercept(void *p) { return 0; }
void *thermal_base = NULL;

/* GPU Stubs */
void get_immediate_gpu_wrap(void) {}
void mtk_gpufreq_register(void *p) {}
