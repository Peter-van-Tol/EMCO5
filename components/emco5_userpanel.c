/* Autogenerated by /opt/linuxcnc/bin/halcompile on Wed Mar  8 13:55:12 2023 -- do not edit */
#include "rtapi.h"
#ifdef RTAPI
#include "rtapi_app.h"
#endif
#include "rtapi_string.h"
#include "rtapi_errno.h"
#include "hal.h"
#include "rtapi_math64.h"

static int comp_id;

#ifdef MODULE_INFO
MODULE_INFO(linuxcnc, "component:emco5_userpanel:EMCO5: Connect the buttons and status lights on user panel");
MODULE_INFO(linuxcnc, "pin:is-idle:bit:0:in:Status pin telling that no program is running:None:None");
MODULE_INFO(linuxcnc, "pin:is-paused:bit:0:in:Status pin telling that a program is paused:None:None");
MODULE_INFO(linuxcnc, "pin:is-running:bit:0:in:Status pin telling that a program is running:None:None");
MODULE_INFO(linuxcnc, "pin:is-gcode-loaded:s32:0:in:Number of gcode lines currently loaded, telling a file is loaded and can be started when set to number >0.:None:None");
MODULE_INFO(linuxcnc, "pin:is-start-pressed:bit:0:in:Input for external start button:None:None");
MODULE_INFO(linuxcnc, "pin:is-pause-pressed:bit:0:in:Input for external pause button:None:None");
MODULE_INFO(linuxcnc, "pin:is-stop-pressed:bit:0:in:Input for external stop button:None:None");
MODULE_INFO(linuxcnc, "pin:status-disabled:bit:0:in:The status which wil be set to the status LED when the function is disabled:None:None");
MODULE_INFO(linuxcnc, "pin:status-enabled:bit:0:in:The status which wil be set to the status LED when the function is enabled:None:None");
MODULE_INFO(linuxcnc, "pin:status-active:bit:0:in:The status which wil be set to the status LED when the function is currently active:None:None");
MODULE_INFO(linuxcnc, "pin:pause:bit:0:out:Pin for pausing a program:None:None");
MODULE_INFO(linuxcnc, "pin:resume:bit:0:out:Pin for resuming a program:None:None");
MODULE_INFO(linuxcnc, "pin:run:bit:0:out:Pin for running a program:None:None");
MODULE_INFO(linuxcnc, "pin:step:bit:0:out:Pin for stepping in a program:None:None");
MODULE_INFO(linuxcnc, "pin:stop:bit:0:out:Pin for stopping a program:None:None");
MODULE_INFO(linuxcnc, "pin:start-status-LED:bit:0:out:Signal for the status LED of the start button:None:None");
MODULE_INFO(linuxcnc, "pin:pause-status-LED:bit:0:out:Signal for the status LED of the pause button:None:None");
MODULE_INFO(linuxcnc, "pin:stop-status-LED:bit:0:out:Signal for the status LED of the stop button:None:None");
MODULE_INFO(linuxcnc, "funct:_:1:");
MODULE_INFO(linuxcnc, "license:GPL");
MODULE_INFO(linuxcnc, "descr: Used for connecting Program start, Pause (Feed hold), and Stop \n    from the user panel to the halui. Also supports stepping when \n    the program is paused. This component can also be created by slapping a\n    large number of `and` and `or` components together, cluttering the HAL-files.\n    This is deemed a cleaner method.");
MODULE_INFO(linuxcnc, "author:Peter van Tol <petertgvantol@gmail.com>");
MODULE_LICENSE("GPL");
#endif // MODULE_INFO


struct __comp_state {
    struct __comp_state *_next;
    hal_bit_t *is_idle;
    hal_bit_t *is_paused;
    hal_bit_t *is_running;
    hal_s32_t *is_gcode_loaded;
    hal_bit_t *is_start_pressed;
    hal_bit_t *is_pause_pressed;
    hal_bit_t *is_stop_pressed;
    hal_bit_t *status_disabled;
    hal_bit_t *status_enabled;
    hal_bit_t *status_active;
    hal_bit_t *pause;
    hal_bit_t *resume;
    hal_bit_t *run;
    hal_bit_t *step;
    hal_bit_t *stop;
    hal_bit_t *start_status_LED;
    hal_bit_t *pause_status_LED;
    hal_bit_t *stop_status_LED;
};
struct __comp_state *__comp_first_inst=0, *__comp_last_inst=0;

static void _(struct __comp_state *__comp_inst, long period);
static int __comp_get_data_size(void);
#undef TRUE
#define TRUE (1)
#undef FALSE
#define FALSE (0)
#undef true
#define true (1)
#undef false
#define false (0)

static int export(char *prefix, long extra_arg) {
    char buf[HAL_NAME_LEN + 1];
    int r = 0;
    int sz = sizeof(struct __comp_state) + __comp_get_data_size();
    struct __comp_state *inst = hal_malloc(sz);
    memset(inst, 0, sz);
    r = hal_pin_bit_newf(HAL_IN, &(inst->is_idle), comp_id,
        "%s.is-idle", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_IN, &(inst->is_paused), comp_id,
        "%s.is-paused", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_IN, &(inst->is_running), comp_id,
        "%s.is-running", prefix);
    if(r != 0) return r;
    r = hal_pin_s32_newf(HAL_IN, &(inst->is_gcode_loaded), comp_id,
        "%s.is-gcode-loaded", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_IN, &(inst->is_start_pressed), comp_id,
        "%s.is-start-pressed", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_IN, &(inst->is_pause_pressed), comp_id,
        "%s.is-pause-pressed", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_IN, &(inst->is_stop_pressed), comp_id,
        "%s.is-stop-pressed", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_IN, &(inst->status_disabled), comp_id,
        "%s.status-disabled", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_IN, &(inst->status_enabled), comp_id,
        "%s.status-enabled", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_IN, &(inst->status_active), comp_id,
        "%s.status-active", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_OUT, &(inst->pause), comp_id,
        "%s.pause", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_OUT, &(inst->resume), comp_id,
        "%s.resume", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_OUT, &(inst->run), comp_id,
        "%s.run", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_OUT, &(inst->step), comp_id,
        "%s.step", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_OUT, &(inst->stop), comp_id,
        "%s.stop", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_OUT, &(inst->start_status_LED), comp_id,
        "%s.start-status-LED", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_OUT, &(inst->pause_status_LED), comp_id,
        "%s.pause-status-LED", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_OUT, &(inst->stop_status_LED), comp_id,
        "%s.stop-status-LED", prefix);
    if(r != 0) return r;
    rtapi_snprintf(buf, sizeof(buf), "%s", prefix);
    r = hal_export_funct(buf, (void(*)(void *inst, long))_, inst, 1, 0, comp_id);
    if(r != 0) return r;
    if(__comp_last_inst) __comp_last_inst->_next = inst;
    __comp_last_inst = inst;
    if(!__comp_first_inst) __comp_first_inst = inst;
    return 0;
}
int rtapi_app_main(void) {
    int r = 0;
    comp_id = hal_init("emco5_userpanel");
    if(comp_id < 0) return comp_id;
    r = export("emco5-userpanel", 0);
    if(r) {
        hal_exit(comp_id);
    } else {
        hal_ready(comp_id);
    }
    return r;
}

void rtapi_app_exit(void) {
    hal_exit(comp_id);
}

#undef FUNCTION
#define FUNCTION(name) static void name(struct __comp_state *__comp_inst, long period)
#undef EXTRA_SETUP
#define EXTRA_SETUP() static int extra_setup(struct __comp_state *__comp_inst, char *prefix, long extra_arg)
#undef EXTRA_CLEANUP
#define EXTRA_CLEANUP() static void extra_cleanup(void)
#undef fperiod
#define fperiod (period * 1e-9)
#undef is_idle
#define is_idle (0+*__comp_inst->is_idle)
#undef is_paused
#define is_paused (0+*__comp_inst->is_paused)
#undef is_running
#define is_running (0+*__comp_inst->is_running)
#undef is_gcode_loaded
#define is_gcode_loaded (0+*__comp_inst->is_gcode_loaded)
#undef is_start_pressed
#define is_start_pressed (0+*__comp_inst->is_start_pressed)
#undef is_pause_pressed
#define is_pause_pressed (0+*__comp_inst->is_pause_pressed)
#undef is_stop_pressed
#define is_stop_pressed (0+*__comp_inst->is_stop_pressed)
#undef status_disabled
#define status_disabled (0+*__comp_inst->status_disabled)
#undef status_enabled
#define status_enabled (0+*__comp_inst->status_enabled)
#undef status_active
#define status_active (0+*__comp_inst->status_active)
#undef pause
#define pause (*__comp_inst->pause)
#undef resume
#define resume (*__comp_inst->resume)
#undef run
#define run (*__comp_inst->run)
#undef step
#define step (*__comp_inst->step)
#undef stop
#define stop (*__comp_inst->stop)
#undef start_status_LED
#define start_status_LED (*__comp_inst->start_status_LED)
#undef pause_status_LED
#define pause_status_LED (*__comp_inst->pause_status_LED)
#undef stop_status_LED
#define stop_status_LED (*__comp_inst->stop_status_LED)


FUNCTION(_) {
#line 43 "emco5_userpanel.comp"
// Actual function
if (is_idle && is_gcode_loaded) {
    // The machine is IDLE and program is loaded:
    // - start button enabled -> action starts program
    // - start button starts program
    
    // Set actions
    pause = false;
    resume = false;
    run = is_start_pressed;
    step = false;
    stop = false;

    // Set indicators
    start_status_LED = status_enabled;
    pause_status_LED = status_disabled;
    stop_status_LED = status_disabled;

} else if (is_running) {
    // The machine is RUNNING:
    // - start button active;
    // - pause button enabled -> action pause program;
    // - stop button enabled -> action stop program;
    
    // Set actions
    pause = is_pause_pressed;
    resume = false;
    run = false;
    step = false;
    stop = is_stop_pressed;

    // Set indicators
    start_status_LED = status_active;
    pause_status_LED = status_enabled;
    stop_status_LED = status_enabled;

} else if (is_paused) {
    // The machine is PAUSED:
    // - pause button active;
    // - start button enabled -> action step program;
    // - stop button enabled -> action stop program;
    
    // Set actions
    pause = false;
    resume = is_pause_pressed;
    run = false;
    step = is_start_pressed;
    stop = is_stop_pressed;

    // Set indicators
    start_status_LED = status_enabled;
    pause_status_LED = status_active;
    stop_status_LED = status_enabled;

} else {
    // The machine has no program loaded or is not ready
    // - all inputs disabled
    
    // Set actions
    pause = false;
    resume = false;
    run = false;
    step = false;
    stop = false;

    // Set indicators
    start_status_LED = status_disabled;
    pause_status_LED = status_disabled;
    stop_status_LED = status_disabled;
}
}

static int __comp_get_data_size(void) { return 0; }