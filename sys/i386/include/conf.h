begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CONF_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CONF_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ACTUALLY_LKM_NOT_KERNEL
end_ifndef

begin_comment
comment|/*  * XXX instead of this, the per-driver declarations should probably be  * put in the "driver.h" headers.  Then ioconf.h could include all the  * "driver.h" headers and drivers would automatically include their  * own "driver.h" header, so we wouldn't need to include ioconf.h here.  * Interrupt handlers should probably be static.  */
end_comment

begin_include
include|#
directive|include
file|"ioconf.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following was copied from the bogusly non-machine-generated  * file<i386/i386/conf.c>.  Eventually the routines should be static.  */
end_comment

begin_decl_stmt
name|d_rdwr_t
name|rawread
decl_stmt|,
name|rawwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|wdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|wdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|wdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|wdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|wddump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|wdsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|wormopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|wormclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|wormstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|wormioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|wormdump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|wormsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|sctargopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|sctargclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|sctargstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|sctargioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|sctargdump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|sctargsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|ptopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ptclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|ptstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ptioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|ptdump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|ptsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|sdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|sdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|sdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|sdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|sddump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|sdsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|stopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|stclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|ststrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|stioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|odopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|odclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|odstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|odioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|odsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|cdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|cdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|cdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|cdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|cdsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|mcdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|mcdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|mcdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|mcdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|mcdsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|scdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|scdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|scdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|scdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|scdsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|matcdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|matcdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|matcdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|matcdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|matcddump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|matcdsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|ataopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ataclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|atastrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ataioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|atasize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|wcdbopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|wcdropen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|wcdbclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|wcdrclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|wcdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|wcdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|chopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|chclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|chioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|wtopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|wtclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|wtstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|wtioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|wtdump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|wtsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|Fdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|fdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|fdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|fdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|vnopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|vnclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|vnstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|vnioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|vndump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|vnsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|meteor_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|meteor_close
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|meteor_read
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|meteor_write
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|meteor_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_mmap_t
name|meteor_mmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|swread
decl_stmt|,
name|swwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|mmopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|mmclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|mmrw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_mmap_t
name|memmmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|mmioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|ptsopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ptsclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|ptsread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|ptswrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|ptsstop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|ptcopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ptcclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|ptcread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|ptcwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|ptcselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|ptydevtotty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ptyioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|snpopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|snpclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|snpread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|snpwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|snpselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|snpioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|logopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|logclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|logread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|logioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|logselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|bquopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|bquclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|bquread
decl_stmt|,
name|bquwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|bquselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|bquioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|lptopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|lptclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|lptwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|lptioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|twopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|twclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|twread
decl_stmt|,
name|twwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|twselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|twdevtotty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|psmopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|psmclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|psmread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|psmselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|psmioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|sndopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|sndclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|sndioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|sndread
decl_stmt|,
name|sndwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|sndselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|fdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|bpfopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|bpfclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|bpfread
decl_stmt|,
name|bpfwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|bpfselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|bpfioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|spkropen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|spkrclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|spkrwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|spkrioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|pcaopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|pcaclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|pcawrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|pcaioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|pcaselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|mseopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|mseclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|mseread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|mseselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|sioopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|sioclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|sioread
decl_stmt|,
name|siowrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|sioioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|siostop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|siodevtotty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|suopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|suclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|suioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|suread
decl_stmt|,
name|suwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|suselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|sustrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|ukopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ukclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ukioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|lkmcopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|lkmcclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|lkmcioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|apmopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|apmclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|apmioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|ctxopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ctxclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|ctxread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|ctxwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ctxioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|sscopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|sscclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|sscioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|sscread
decl_stmt|,
name|sscwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|sscselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|sscstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|cxopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|cxclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|cxread
decl_stmt|,
name|cxwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|cxioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|cxselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|cxstop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|cxdevtotty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|gpopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|gpclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|gpwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|gpioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|gscopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|gscclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|gscread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|gscioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|crdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|crdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|crdread
decl_stmt|,
name|crdwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|crdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|crdselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|joyopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|joyclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|joyread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|joyioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|ascopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ascclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|ascread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ascioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|ascselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|tunopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|tunclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|tunread
decl_stmt|,
name|tunwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|tunioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|tunselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|spigot_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|spigot_close
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|spigot_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|spigot_read
decl_stmt|,
name|spigot_write
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|spigot_select
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_mmap_t
name|spigot_mmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|cyopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|cyclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|cyread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|cywrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|cyioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|cystop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|cydevtotty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|dgbopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|dgbclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|dgbread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|dgbwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|dgbioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|dgbstop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|dgbdevtotty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|siopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|siclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|siread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|siwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|siioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|sistop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|sidevtotty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|ityopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ityclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|ityread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|itywrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ityioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|itydevtotty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|nicopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|nicclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|nicioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|nnicopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|nnicclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|nnicioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|isdnopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|isdnclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|isdnread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|isdnioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|itelopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|itelclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|itelread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|itelwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|itelioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|ispyopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ispyclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|ispyread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|ispywrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ispyioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|rcopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|rcclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|rcread
decl_stmt|,
name|rcwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|rcioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|rcstop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|rcdevtotty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|labpcopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|labpcclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|labpcstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|labpcioctl
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CONF_H_ */
end_comment

end_unit

