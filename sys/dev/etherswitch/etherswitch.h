begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SYS_DEV_ETHERSWITCH_ETHERSWITCH_H
end_ifndef

begin_define
define|#
directive|define
name|__SYS_DEV_ETHERSWITCH_ETHERSWITCH_H
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|devclass_t
name|etherswitch_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|driver_t
name|etherswitch_driver
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_struct
struct|struct
name|etherswitch_reg
block|{
name|uint16_t
name|reg
decl_stmt|;
name|uint16_t
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|etherswitch_reg
name|etherswitch_reg_t
typedef|;
end_typedef

begin_struct
struct|struct
name|etherswitch_phyreg
block|{
name|uint16_t
name|phy
decl_stmt|;
name|uint16_t
name|reg
decl_stmt|;
name|uint16_t
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|etherswitch_phyreg
name|etherswitch_phyreg_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ETHERSWITCH_NAMEMAX
value|64
end_define

begin_struct
struct|struct
name|etherswitch_info
block|{
name|int
name|es_nports
decl_stmt|;
name|int
name|es_nvlangroups
decl_stmt|;
name|char
name|es_name
index|[
name|ETHERSWITCH_NAMEMAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|etherswitch_info
name|etherswitch_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|etherswitch_port
block|{
name|int
name|es_port
decl_stmt|;
name|int
name|es_vlangroup
decl_stmt|;
union|union
block|{
name|struct
name|ifreq
name|es_uifr
decl_stmt|;
name|struct
name|ifmediareq
name|es_uifmr
decl_stmt|;
block|}
name|es_ifu
union|;
define|#
directive|define
name|es_ifr
value|es_ifu.es_uifr
define|#
directive|define
name|es_ifmr
value|es_ifu.es_uifmr
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|etherswitch_port
name|etherswitch_port_t
typedef|;
end_typedef

begin_struct
struct|struct
name|etherswitch_vlangroup
block|{
name|int
name|es_vlangroup
decl_stmt|;
name|int
name|es_vid
decl_stmt|;
name|int
name|es_member_ports
decl_stmt|;
name|int
name|es_untagged_ports
decl_stmt|;
name|int
name|es_fid
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|etherswitch_vlangroup
name|etherswitch_vlangroup_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ETHERSWITCH_PORTMASK
parameter_list|(
name|_port
parameter_list|)
value|(1<< (_port))
end_define

begin_define
define|#
directive|define
name|IOETHERSWITCHGETINFO
value|_IOR('i', 1, etherswitch_info_t)
end_define

begin_define
define|#
directive|define
name|IOETHERSWITCHGETREG
value|_IOWR('i', 2, etherswitch_reg_t)
end_define

begin_define
define|#
directive|define
name|IOETHERSWITCHSETREG
value|_IOW('i', 3, etherswitch_reg_t)
end_define

begin_define
define|#
directive|define
name|IOETHERSWITCHGETPORT
value|_IOWR('i', 4, etherswitch_port_t)
end_define

begin_define
define|#
directive|define
name|IOETHERSWITCHSETPORT
value|_IOW('i', 5, etherswitch_port_t)
end_define

begin_define
define|#
directive|define
name|IOETHERSWITCHGETVLANGROUP
value|_IOWR('i', 6, etherswitch_vlangroup_t)
end_define

begin_define
define|#
directive|define
name|IOETHERSWITCHSETVLANGROUP
value|_IOW('i', 7, etherswitch_vlangroup_t)
end_define

begin_define
define|#
directive|define
name|IOETHERSWITCHGETPHYREG
value|_IOWR('i', 8, etherswitch_phyreg_t)
end_define

begin_define
define|#
directive|define
name|IOETHERSWITCHSETPHYREG
value|_IOW('i', 9, etherswitch_phyreg_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

