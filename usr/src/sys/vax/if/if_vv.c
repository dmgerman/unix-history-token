begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_vv.c	6.7	85/05/22	*/
end_comment

begin_include
include|#
directive|include
file|"vv.h"
end_include

begin_comment
comment|/*  * Proteon proNET-10 and proNET-80 token ring driver.  * The name of this device driver derives from the old MIT  * name of V2LNI for the proNET hardware, would would abbreviate  * to "v2", but this won't work right. Thus the name is "vv".  *  * This driver is compatible with the proNET 10 meagbit and  * 80 megabit token ring interfaces (models p1000 and p1080).  *  * TRAILERS: You must turn off trailers via ifconfig if you want to share  * a ring with software using the following protocol types:  *  3: Address Resolution Protocol  *  4: HDLC (old Proteon drivers)  *  5: VAX Debugging Protocol (never used)  * This is because the protocol type values chosen for trailers  * conflict with these protocols. It's too late to change either now.  *  * HARDWARE COMPATABILITY: This driver requires that the HSBU (p1001)  * have a serial number>= 040, which is about March, 1982. Older  * HSBUs do not carry across 64kbyte boundaries. The old warning  * about use without Wire Centers applies only to CTL (p1002) cards with  * serial<= 057, which have not received ECO 176-743, which was  * implemented in March, 1982. Most such CTLs have received this ECO,  * but they are only compatible with the old HSBUs (<=039) anyways.  */
end_comment

begin_include
include|#
directive|include
file|"../machine/pte.h"
end_include

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"mbuf.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"protosw.h"
end_include

begin_include
include|#
directive|include
file|"socket.h"
end_include

begin_include
include|#
directive|include
file|"vmmac.h"
end_include

begin_include
include|#
directive|include
file|"errno.h"
end_include

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_include
include|#
directive|include
file|"../net/if.h"
end_include

begin_include
include|#
directive|include
file|"../net/netisr.h"
end_include

begin_include
include|#
directive|include
file|"../net/route.h"
end_include

begin_include
include|#
directive|include
file|"../netinet/in.h"
end_include

begin_include
include|#
directive|include
file|"../netinet/in_systm.h"
end_include

begin_include
include|#
directive|include
file|"../netinet/ip.h"
end_include

begin_include
include|#
directive|include
file|"../netinet/ip_var.h"
end_include

begin_include
include|#
directive|include
file|"../vax/cpu.h"
end_include

begin_include
include|#
directive|include
file|"../vax/mtpr.h"
end_include

begin_include
include|#
directive|include
file|"if_vv.h"
end_include

begin_include
include|#
directive|include
file|"if_uba.h"
end_include

begin_include
include|#
directive|include
file|"../vaxuba/ubareg.h"
end_include

begin_include
include|#
directive|include
file|"../vaxuba/ubavar.h"
end_include

begin_comment
comment|/*  * 80 megabit configuration  * Uncomment the next line if you are using the 80 megabit system. The  * only change is the disposition of packets with parity/link_data_error  * indication.  */
end_comment

begin_comment
comment|/* #define PRONET80 */
end_comment

begin_comment
comment|/*  *    maximum transmission unit definition --  *        you can set VVMTU at anything from 576 to 2024.  *        1536 is a popular "large" value, because it is a multiple  *	  of 512, which the trailer scheme likes.  *        The absolute maximum size is 2024, which is enforced.  */
end_comment

begin_define
define|#
directive|define
name|VVMTU
value|(1024)
end_define

begin_define
define|#
directive|define
name|VVMRU
value|(VVMTU + 16)
end_define

begin_define
define|#
directive|define
name|VVBUFSIZE
value|(VVMRU + sizeof(struct vv_header))
end_define

begin_if
if|#
directive|if
name|VVMTU
operator|>
literal|2024
end_if

begin_undef
undef|#
directive|undef
name|VVMTU
end_undef

begin_undef
undef|#
directive|undef
name|VVMRU
end_undef

begin_undef
undef|#
directive|undef
name|VVBUFSIZE
end_undef

begin_define
define|#
directive|define
name|VVBUFSIZE
value|(2046)
end_define

begin_define
define|#
directive|define
name|VVMRU
value|(VVBUFSIZE - sizeof (struct vv_header))
end_define

begin_define
define|#
directive|define
name|VVMTU
value|(VVMRU - 16)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *   debugging and tracing stuff  */
end_comment

begin_decl_stmt
name|int
name|vv_tracehdr
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 => trace headers (slowly!!) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|proteon
end_ifndef

begin_decl_stmt
name|int
name|vv_logreaderrors
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 => log all read errors */
end_comment

begin_else
else|#
directive|else
else|proteon
end_else

begin_decl_stmt
name|int
name|vv_logerrors
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 => log all i/o errors */
end_comment

begin_endif
endif|#
directive|endif
endif|proteon
end_endif

begin_define
define|#
directive|define
name|vvtracehdr
value|if (vv_tracehdr) vvprt_hdr
end_define

begin_define
define|#
directive|define
name|vvprintf
value|if (vv_logerrors&& vs->vs_if.if_flags& IFF_DEBUG) printf
end_define

begin_comment
comment|/*  * externals, types, etc.  */
end_comment

begin_decl_stmt
name|int
name|vvprobe
argument_list|()
decl_stmt|,
name|vvattach
argument_list|()
decl_stmt|,
name|vvreset
argument_list|()
decl_stmt|,
name|vvinit
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vvidentify
argument_list|()
decl_stmt|,
name|vvstart
argument_list|()
decl_stmt|,
name|vvxint
argument_list|()
decl_stmt|,
name|vvwatchdog
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vvrint
argument_list|()
decl_stmt|,
name|vvoutput
argument_list|()
decl_stmt|,
name|vvioctl
argument_list|()
decl_stmt|,
name|vvsetaddr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uba_device
modifier|*
name|vvinfo
index|[
name|NVV
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|vvstd
index|[]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uba_driver
name|vvdriver
init|=
block|{
name|vvprobe
block|,
literal|0
block|,
name|vvattach
block|,
literal|0
block|,
name|vvstd
block|,
literal|"vv"
block|,
name|vvinfo
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VVUNIT
parameter_list|(
name|x
parameter_list|)
value|minor(x)
end_define

begin_define
define|#
directive|define
name|LOOPBACK
end_define

begin_comment
comment|/* use loopback for packets meant for us */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LOOPBACK
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|ifnet
name|loif
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Software status of each interface.  *  * Each interface is referenced by a network interface structure,  * vs_if, which the routing code uses to locate the interface.  * This structure contains the output queue for the interface, its address, ...  * We also have, for each interface, a UBA interface structure, which  * contains information about the UNIBUS resources held by the interface:  * map registers, buffered data paths, etc.  Information is cached in this  * structure for use by the if_uba.c routines in running the interface  * efficiently.  */
end_comment

begin_struct
struct|struct
name|vv_softc
block|{
name|struct
name|ifnet
name|vs_if
decl_stmt|;
comment|/* network-visible interface */
name|struct
name|ifuba
name|vs_ifuba
decl_stmt|;
comment|/* UNIBUS resources */
name|short
name|vs_oactive
decl_stmt|;
comment|/* is output active */
name|short
name|vs_olen
decl_stmt|;
comment|/* length of last output */
name|u_short
name|vs_lastx
decl_stmt|;
comment|/* address of last packet sent */
name|u_short
name|vs_lastr
decl_stmt|;
comment|/* address of last packet received */
name|short
name|vs_tries
decl_stmt|;
comment|/* transmit current retry count */
name|short
name|vs_init
decl_stmt|;
comment|/* number of ring inits */
name|short
name|vs_refused
decl_stmt|;
comment|/* number of packets refused */
name|short
name|vs_timeouts
decl_stmt|;
comment|/* number of transmit timeouts */
name|short
name|vs_otimeout
decl_stmt|;
comment|/* number of output timeouts */
name|short
name|vs_ibadf
decl_stmt|;
comment|/* number of input bad formats */
name|short
name|vs_parity
decl_stmt|;
comment|/* number of parity errors on 10 meg, */
comment|/* link data errors on 80 meg */
block|}
name|vv_softc
index|[
name|NVV
index|]
struct|;
end_struct

begin_comment
comment|/*  * probe the interface to see that the registers exist, and then  * cause an interrupt to find its vector  */
end_comment

begin_macro
name|vvprobe
argument_list|(
argument|reg
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|reg
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|br
decl_stmt|,
name|cvec
decl_stmt|;
specifier|register
name|struct
name|vvreg
modifier|*
name|addr
decl_stmt|;
ifdef|#
directive|ifdef
name|lint
name|br
operator|=
literal|0
expr_stmt|;
name|cvec
operator|=
name|br
expr_stmt|;
name|br
operator|=
name|cvec
expr_stmt|;
endif|#
directive|endif
name|addr
operator|=
operator|(
expr|struct
name|vvreg
operator|*
operator|)
name|reg
expr_stmt|;
comment|/* reset interface, enable, and wait till dust settles */
name|addr
operator|->
name|vvicsr
operator|=
name|VV_RST
expr_stmt|;
name|addr
operator|->
name|vvocsr
operator|=
name|VV_RST
expr_stmt|;
name|DELAY
argument_list|(
literal|100000
argument_list|)
expr_stmt|;
comment|/* generate interrupt by doing 1 word DMA from 0 in uba space!! */
name|addr
operator|->
name|vvoba
operator|=
literal|0
expr_stmt|;
comment|/* low 16 bits */
name|addr
operator|->
name|vvoea
operator|=
literal|0
expr_stmt|;
comment|/* extended bits */
name|addr
operator|->
name|vvowc
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* for 1 word */
name|addr
operator|->
name|vvocsr
operator|=
name|VV_IEN
operator||
name|VV_DEN
expr_stmt|;
comment|/* start the DMA, with interrupt */
name|DELAY
argument_list|(
literal|100000
argument_list|)
expr_stmt|;
name|addr
operator|->
name|vvocsr
operator|=
name|VV_RST
expr_stmt|;
comment|/* clear out the CSR */
if|if
condition|(
name|cvec
operator|&&
name|cvec
operator|!=
literal|0x200
condition|)
name|cvec
operator|-=
literal|4
expr_stmt|;
comment|/* backup so vector => receive */
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Interface exists: make available by filling in network interface  * record.  System will initialize the interface when it is ready  * to accept packets.  */
end_comment

begin_macro
name|vvattach
argument_list|(
argument|ui
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|vv_softc
modifier|*
name|vs
decl_stmt|;
name|vs
operator|=
operator|&
name|vv_softc
index|[
name|ui
operator|->
name|ui_unit
index|]
expr_stmt|;
name|vs
operator|->
name|vs_if
operator|.
name|if_unit
operator|=
name|ui
operator|->
name|ui_unit
expr_stmt|;
name|vs
operator|->
name|vs_if
operator|.
name|if_name
operator|=
literal|"vv"
expr_stmt|;
name|vs
operator|->
name|vs_if
operator|.
name|if_mtu
operator|=
name|VVMTU
expr_stmt|;
name|vs
operator|->
name|vs_if
operator|.
name|if_init
operator|=
name|vvinit
expr_stmt|;
name|vs
operator|->
name|vs_if
operator|.
name|if_ioctl
operator|=
name|vvioctl
expr_stmt|;
name|vs
operator|->
name|vs_if
operator|.
name|if_output
operator|=
name|vvoutput
expr_stmt|;
name|vs
operator|->
name|vs_if
operator|.
name|if_reset
operator|=
name|vvreset
expr_stmt|;
name|vs
operator|->
name|vs_if
operator|.
name|if_timer
operator|=
literal|0
expr_stmt|;
name|vs
operator|->
name|vs_if
operator|.
name|if_watchdog
operator|=
name|vvwatchdog
expr_stmt|;
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_flags
operator|=
name|UBA_CANTWAIT
operator||
name|UBA_NEEDBDP
operator||
name|UBA_NEED16
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|VAX750
argument_list|)
comment|/* don't chew up 750 bdp's */
if|if
condition|(
name|cpu
operator|==
name|VAX_750
operator|&&
name|ui
operator|->
name|ui_unit
operator|>
literal|0
condition|)
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_flags
operator|&=
operator|~
name|UBA_NEEDBDP
expr_stmt|;
endif|#
directive|endif
name|if_attach
argument_list|(
operator|&
name|vs
operator|->
name|vs_if
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Reset of interface after UNIBUS reset.  * If interface is on specified uba, reset its state.  */
end_comment

begin_macro
name|vvreset
argument_list|(
argument|unit
argument_list|,
argument|uban
argument_list|)
end_macro

begin_decl_stmt
name|int
name|unit
decl_stmt|,
name|uban
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
if|if
condition|(
name|unit
operator|>=
name|NVV
operator|||
operator|(
name|ui
operator|=
name|vvinfo
index|[
name|unit
index|]
operator|)
operator|==
literal|0
operator|||
name|ui
operator|->
name|ui_alive
operator|==
literal|0
operator|||
name|ui
operator|->
name|ui_ubanum
operator|!=
name|uban
condition|)
return|return;
name|printf
argument_list|(
literal|" vv%d"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|vvinit
argument_list|(
name|unit
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Initialization of interface; clear recorded pending  * operations, and reinitialize UNIBUS usage.  */
end_comment

begin_macro
name|vvinit
argument_list|(
argument|unit
argument_list|)
end_macro

begin_decl_stmt
name|int
name|unit
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|vv_softc
modifier|*
name|vs
decl_stmt|;
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
specifier|register
name|struct
name|vvreg
modifier|*
name|addr
decl_stmt|;
specifier|register
name|struct
name|sockaddr_in
modifier|*
name|sin
decl_stmt|;
specifier|register
name|int
name|ubainfo
decl_stmt|,
name|s
decl_stmt|;
name|vs
operator|=
operator|&
name|vv_softc
index|[
name|unit
index|]
expr_stmt|;
name|ui
operator|=
name|vvinfo
index|[
name|unit
index|]
expr_stmt|;
name|sin
operator|=
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
operator|&
name|vs
operator|->
name|vs_if
operator|.
name|if_addr
expr_stmt|;
comment|/* 	 * If the network number is still zero, we've been 	 * called too soon. 	 */
if|if
condition|(
name|in_netof
argument_list|(
name|sin
operator|->
name|sin_addr
argument_list|)
operator|==
literal|0
condition|)
return|return;
name|addr
operator|=
operator|(
expr|struct
name|vvreg
operator|*
operator|)
name|ui
operator|->
name|ui_addr
expr_stmt|;
if|if
condition|(
name|if_ubainit
argument_list|(
operator|&
name|vs
operator|->
name|vs_ifuba
argument_list|,
name|ui
operator|->
name|ui_ubanum
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|vv_header
argument_list|)
argument_list|,
operator|(
name|int
operator|)
name|btoc
argument_list|(
name|VVMTU
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"vv%d: can't initialize, if_ubainit() failed\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|vs
operator|->
name|vs_if
operator|.
name|if_flags
operator|&=
operator|~
name|IFF_UP
expr_stmt|;
return|return;
block|}
comment|/* 	 * Now that the uba is set up, figure out our address and 	 * update complete our host address. 	 */
if|if
condition|(
operator|(
name|vs
operator|->
name|vs_if
operator|.
name|if_host
index|[
literal|0
index|]
operator|=
name|vvidentify
argument_list|(
name|unit
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
name|vs
operator|->
name|vs_if
operator|.
name|if_flags
operator|&=
operator|~
name|IFF_UP
expr_stmt|;
return|return;
block|}
name|printf
argument_list|(
literal|"vv%d: host %d\n"
argument_list|,
name|unit
argument_list|,
name|vs
operator|->
name|vs_if
operator|.
name|if_host
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|sin
operator|->
name|sin_addr
operator|=
name|if_makeaddr
argument_list|(
name|vs
operator|->
name|vs_if
operator|.
name|if_net
argument_list|,
name|vs
operator|->
name|vs_if
operator|.
name|if_host
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* 	 * Reset the interface, and stay in the ring 	 */
name|addr
operator|->
name|vvocsr
operator|=
name|VV_RST
expr_stmt|;
comment|/* take over output */
name|addr
operator|->
name|vvocsr
operator|=
name|VV_CPB
expr_stmt|;
comment|/* clear packet buffer */
name|addr
operator|->
name|vvicsr
operator|=
name|VV_RST
operator||
name|VV_HEN
expr_stmt|;
comment|/* take over input, */
comment|/* keep relay closed */
name|DELAY
argument_list|(
literal|500000
argument_list|)
expr_stmt|;
comment|/* let contacts settle */
name|vs
operator|->
name|vs_init
operator|=
literal|0
expr_stmt|;
comment|/* clear counters, etc. */
name|vs
operator|->
name|vs_refused
operator|=
literal|0
expr_stmt|;
name|vs
operator|->
name|vs_timeouts
operator|=
literal|0
expr_stmt|;
name|vs
operator|->
name|vs_otimeout
operator|=
literal|0
expr_stmt|;
name|vs
operator|->
name|vs_ibadf
operator|=
literal|0
expr_stmt|;
name|vs
operator|->
name|vs_parity
operator|=
literal|0
expr_stmt|;
name|vs
operator|->
name|vs_lastx
operator|=
literal|256
expr_stmt|;
comment|/* an invalid address */
name|vs
operator|->
name|vs_lastr
operator|=
literal|256
expr_stmt|;
comment|/* an invalid address */
comment|/* 	 * Hang a receive and start any 	 * pending writes by faking a transmit complete. 	 */
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
name|ubainfo
operator|=
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_r
operator|.
name|ifrw_info
expr_stmt|;
name|addr
operator|->
name|vviba
operator|=
operator|(
name|u_short
operator|)
name|ubainfo
expr_stmt|;
name|addr
operator|->
name|vviea
operator|=
call|(
name|u_short
call|)
argument_list|(
name|ubainfo
operator|>>
literal|16
argument_list|)
expr_stmt|;
name|addr
operator|->
name|vviwc
operator|=
operator|-
operator|(
name|VVBUFSIZE
operator|)
operator|>>
literal|1
expr_stmt|;
name|addr
operator|->
name|vvicsr
operator|=
name|VV_IEN
operator||
name|VV_HEN
operator||
name|VV_DEN
operator||
name|VV_ENB
expr_stmt|;
name|vs
operator|->
name|vs_oactive
operator|=
literal|1
expr_stmt|;
name|vs
operator|->
name|vs_if
operator|.
name|if_flags
operator||=
name|IFF_UP
operator||
name|IFF_RUNNING
expr_stmt|;
name|vvxint
argument_list|(
name|unit
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|if_rtinit
argument_list|(
operator|&
name|vs
operator|->
name|vs_if
argument_list|,
name|RTF_UP
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Do a moderately thorough self-test in all three modes. Mostly  * to keeps defective nodes off the ring, rather than to be especially  * thorough. The key issue is to detect any cable breaks before joining  * the ring. Return our node address on success, return -1 on failure.  *  */
end_comment

begin_comment
comment|/* the three self-test modes */
end_comment

begin_decl_stmt
specifier|static
name|u_short
name|vv_modes
index|[]
init|=
block|{
name|VV_STE
operator||
name|VV_LPB
block|,
comment|/* digital loopback */
name|VV_STE
block|,
comment|/* analog loopback */
name|VV_HEN
comment|/* network mode */
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|vvidentify
argument_list|(
argument|unit
argument_list|)
end_macro

begin_decl_stmt
name|int
name|unit
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|vv_softc
modifier|*
name|vs
decl_stmt|;
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
specifier|register
name|struct
name|vvreg
modifier|*
name|addr
decl_stmt|;
specifier|register
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
specifier|register
name|struct
name|vv_header
modifier|*
name|v
decl_stmt|;
specifier|register
name|int
name|ubainfo
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|,
name|successes
decl_stmt|,
name|failures
decl_stmt|,
name|waitcount
decl_stmt|;
name|u_short
name|shost
init|=
operator|-
literal|1
decl_stmt|;
name|vs
operator|=
operator|&
name|vv_softc
index|[
name|unit
index|]
expr_stmt|;
name|ui
operator|=
name|vvinfo
index|[
name|unit
index|]
expr_stmt|;
name|addr
operator|=
operator|(
expr|struct
name|vvreg
operator|*
operator|)
name|ui
operator|->
name|ui_addr
expr_stmt|;
comment|/* 	 * Build a multicast message to identify our address 	 * We need do this only once, since nobody else is about to use 	 * the intermediate transmit buffer (ifu_w.ifrw_addr) that 	 * if_ubainit() aquired for us. 	 */
name|m
operator|=
name|m_get
argument_list|(
name|M_DONTWAIT
argument_list|,
name|MT_HEADER
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"vv%d: can't initialize, m_get() failed\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|m
operator|->
name|m_next
operator|=
literal|0
expr_stmt|;
name|m
operator|->
name|m_off
operator|=
name|MMINOFF
expr_stmt|;
name|m
operator|->
name|m_len
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|vv_header
argument_list|)
expr_stmt|;
name|v
operator|=
name|mtod
argument_list|(
name|m
argument_list|,
expr|struct
name|vv_header
operator|*
argument_list|)
expr_stmt|;
name|v
operator|->
name|vh_dhost
operator|=
name|VV_BROADCAST
expr_stmt|;
comment|/* multicast destination address */
name|v
operator|->
name|vh_shost
operator|=
literal|0
expr_stmt|;
comment|/* will be overwritten with ours */
name|v
operator|->
name|vh_version
operator|=
name|RING_VERSION
expr_stmt|;
name|v
operator|->
name|vh_type
operator|=
name|RING_DIAGNOSTICS
expr_stmt|;
name|v
operator|->
name|vh_info
operator|=
literal|0
expr_stmt|;
comment|/* map xmit message into uba, copying to intermediate buffer */
name|vs
operator|->
name|vs_olen
operator|=
name|if_wubaput
argument_list|(
operator|&
name|vs
operator|->
name|vs_ifuba
argument_list|,
name|m
argument_list|)
expr_stmt|;
comment|/* 	 * For each of the modes (digital, analog, network), go through 	 * a self-test that requires me to send VVIDENTSUCC good packets 	 * in VVIDENTRETRY attempts. Use broadcast destination to find out 	 * who I am, then use this as my address to check my address match 	 * logic. Only data checked is the vh_type field. 	 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|3
condition|;
name|i
operator|++
control|)
block|{
name|successes
operator|=
literal|0
expr_stmt|;
comment|/* clear successes for this mode */
name|failures
operator|=
literal|0
expr_stmt|;
comment|/* and clear failures, too */
comment|/* take over device, and leave ring */
name|addr
operator|->
name|vvicsr
operator|=
name|VV_RST
expr_stmt|;
name|addr
operator|->
name|vvocsr
operator|=
name|VV_RST
expr_stmt|;
name|addr
operator|->
name|vvicsr
operator|=
name|vv_modes
index|[
name|i
index|]
expr_stmt|;
comment|/* test mode */
comment|/* 		 * let the flag and token timers pop so that the init ring bit 		 * will be allowed to work, by waiting about 1 second 		 */
name|DELAY
argument_list|(
literal|1000000L
argument_list|)
expr_stmt|;
comment|/* 		 * retry loop  		 */
while|while
condition|(
operator|(
name|successes
operator|<
name|VVIDENTSUCC
operator|)
operator|&&
operator|(
name|failures
operator|<
name|VVIDENTRETRY
operator|)
condition|)
block|{
comment|/* start a receive */
name|ubainfo
operator|=
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_r
operator|.
name|ifrw_info
expr_stmt|;
name|addr
operator|->
name|vvicsr
operator|=
name|VV_RST
operator||
name|vv_modes
index|[
name|i
index|]
expr_stmt|;
comment|/* abort last */
name|addr
operator|->
name|vviba
operator|=
operator|(
name|u_short
operator|)
name|ubainfo
expr_stmt|;
name|addr
operator|->
name|vviea
operator|=
call|(
name|u_short
call|)
argument_list|(
name|ubainfo
operator|>>
literal|16
argument_list|)
expr_stmt|;
name|addr
operator|->
name|vviwc
operator|=
operator|-
operator|(
name|VVBUFSIZE
operator|)
operator|>>
literal|1
expr_stmt|;
name|addr
operator|->
name|vvicsr
operator|=
name|vv_modes
index|[
name|i
index|]
operator||
name|VV_DEN
operator||
name|VV_ENB
expr_stmt|;
comment|/* purge stale data from BDP */
if|if
condition|(
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_flags
operator|&
name|UBA_NEEDBDP
condition|)
name|UBAPURGE
argument_list|(
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_uba
argument_list|,
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_w
operator|.
name|ifrw_bdp
argument_list|)
expr_stmt|;
comment|/* do a transmit */
name|ubainfo
operator|=
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_w
operator|.
name|ifrw_info
expr_stmt|;
name|addr
operator|->
name|vvocsr
operator|=
name|VV_RST
expr_stmt|;
comment|/* abort last try */
name|addr
operator|->
name|vvoba
operator|=
operator|(
name|u_short
operator|)
name|ubainfo
expr_stmt|;
name|addr
operator|->
name|vvoea
operator|=
call|(
name|u_short
call|)
argument_list|(
name|ubainfo
operator|>>
literal|16
argument_list|)
expr_stmt|;
name|addr
operator|->
name|vvowc
operator|=
operator|-
operator|(
operator|(
name|vs
operator|->
name|vs_olen
operator|+
literal|1
operator|)
operator|>>
literal|1
operator|)
expr_stmt|;
name|addr
operator|->
name|vvocsr
operator|=
name|VV_CPB
operator||
name|VV_DEN
operator||
name|VV_INR
operator||
name|VV_ENB
expr_stmt|;
comment|/* poll receive side for completion */
name|DELAY
argument_list|(
literal|10000
argument_list|)
expr_stmt|;
comment|/* give it a chance */
for|for
control|(
name|waitcount
operator|=
literal|0
init|;
name|waitcount
operator|<
literal|10
condition|;
name|waitcount
operator|++
control|)
block|{
if|if
condition|(
name|addr
operator|->
name|vvicsr
operator|&
name|VV_RDY
condition|)
goto|goto
name|gotit
goto|;
name|DELAY
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
block|}
name|failures
operator|++
expr_stmt|;
comment|/* no luck */
continue|continue;
name|gotit
label|:
comment|/* we got something--is it any good? */
if|if
condition|(
operator|(
name|addr
operator|->
name|vvicsr
operator|&
operator|(
name|VVRERR
operator||
name|VV_LDE
operator|)
operator|)
operator|||
operator|(
name|ADDR
operator|->
name|vvocsr
operator|&
operator|(
name|VVXERR
operator||
name|VV_RFS
operator|)
operator|)
condition|)
block|{
name|failures
operator|++
expr_stmt|;
continue|continue;
block|}
comment|/* Purge BDP before looking at received packet */
if|if
condition|(
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_flags
operator|&
name|UBA_NEEDBDP
condition|)
name|UBAPURGE
argument_list|(
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_uba
argument_list|,
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_r
operator|.
name|ifrw_bdp
argument_list|)
expr_stmt|;
name|m
operator|=
name|if_rubaget
argument_list|(
operator|&
name|vs
operator|->
name|vs_ifuba
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|vv_header
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|!=
name|NULL
condition|)
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|v
operator|=
operator|(
expr|struct
name|vv_header
operator|*
operator|)
operator|(
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_r
operator|.
name|ifrw_addr
operator|)
expr_stmt|;
comment|/* check message type, catch our node address */
if|if
condition|(
operator|(
name|v
operator|->
name|vh_type
operator|&
literal|0xff
operator|)
operator|==
name|RING_DIAGNOSTICS
condition|)
block|{
if|if
condition|(
name|shost
operator|==
operator|-
literal|1
condition|)
block|{
name|shost
operator|=
name|v
operator|->
name|vh_shost
operator|&
literal|0xff
expr_stmt|;
comment|/* send to ourself now */
operator|(
operator|(
expr|struct
name|vv_header
operator|*
operator|)
operator|(
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_r
operator|.
name|ifrw_addr
operator|)
operator|)
operator|->
name|vh_dhost
operator|=
name|shost
expr_stmt|;
block|}
name|successes
operator|++
expr_stmt|;
name|v
operator|->
name|vh_type
operator|=
literal|0
expr_stmt|;
comment|/* clear to check again */
block|}
block|}
if|if
condition|(
name|failures
operator|>=
name|VVIDENTRETRY
condition|)
block|{
name|printf
argument_list|(
literal|"vv%d: failed self-test after %d tries \ in %s mode\n"
argument_list|,
name|unit
argument_list|,
name|VVIDENTRETRY
argument_list|,
name|i
operator|==
literal|0
condition|?
literal|"digital loopback"
else|:
operator|(
name|i
operator|==
literal|1
condition|?
literal|"analog loopback"
else|:
literal|"network"
operator|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"vv%d: icsr = %b, ocsr = %b\n"
argument_list|,
name|unit
argument_list|,
literal|0xffff
operator|&
name|addr
operator|->
name|vvicsr
argument_list|,
name|VV_IBITS
argument_list|,
literal|0xffff
operator|&
name|addr
operator|->
name|vvocsr
argument_list|,
name|VV_OBITS
argument_list|)
expr_stmt|;
name|addr
operator|->
name|vvicsr
operator|=
name|VV_RST
expr_stmt|;
comment|/* kill the sick board */
name|addr
operator|->
name|vvocsr
operator|=
name|VV_RST
expr_stmt|;
name|shost
operator|=
operator|-
literal|1
expr_stmt|;
goto|goto
name|done
goto|;
block|}
block|}
name|done
label|:
comment|/* deallocate mbuf used for send packet (won't be one, anyways) */
if|if
condition|(
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_xtofree
condition|)
block|{
name|m_freem
argument_list|(
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_xtofree
argument_list|)
expr_stmt|;
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_xtofree
operator|=
literal|0
expr_stmt|;
block|}
return|return
operator|(
name|shost
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Start or restart output on interface.  * If interface is active, this is a retransmit, so just  * restuff registers and go.  * If interface is not already active, get another datagram  * to send off of the interface queue, and map it to the interface  * before starting the output.  */
end_comment

begin_macro
name|vvstart
argument_list|(
argument|dev
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
specifier|register
name|struct
name|vv_softc
modifier|*
name|vs
decl_stmt|;
specifier|register
name|struct
name|vvreg
modifier|*
name|addr
decl_stmt|;
specifier|register
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
specifier|register
name|int
name|unit
decl_stmt|,
name|ubainfo
decl_stmt|,
name|dest
decl_stmt|,
name|s
decl_stmt|;
name|unit
operator|=
name|VVUNIT
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|ui
operator|=
name|vvinfo
index|[
name|unit
index|]
expr_stmt|;
name|vs
operator|=
operator|&
name|vv_softc
index|[
name|unit
index|]
expr_stmt|;
if|if
condition|(
name|vs
operator|->
name|vs_oactive
condition|)
goto|goto
name|restart
goto|;
comment|/* 	 * Not already active: dequeue another request 	 * and map it to the UNIBUS.  If no more requests, 	 * just return. 	 */
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
name|IF_DEQUEUE
argument_list|(
operator|&
name|vs
operator|->
name|vs_if
operator|.
name|if_snd
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|==
name|NULL
condition|)
block|{
name|vs
operator|->
name|vs_oactive
operator|=
literal|0
expr_stmt|;
return|return;
block|}
name|dest
operator|=
name|mtod
argument_list|(
name|m
argument_list|,
expr|struct
name|vv_header
operator|*
argument_list|)
operator|->
name|vh_dhost
expr_stmt|;
name|vs
operator|->
name|vs_olen
operator|=
name|if_wubaput
argument_list|(
operator|&
name|vs
operator|->
name|vs_ifuba
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|vs
operator|->
name|vs_lastx
operator|=
name|dest
expr_stmt|;
name|restart
label|:
comment|/* 	 * Have request mapped to UNIBUS for transmission. 	 * Purge any stale data from this BDP, and start the output. 	 * 	 * Make sure this packet will fit in the interface. 	 */
if|if
condition|(
name|vs
operator|->
name|vs_olen
operator|>
name|VVBUFSIZE
condition|)
block|{
name|printf
argument_list|(
literal|"vv%d vs_olen: %d> VVBUFSIZE\n"
argument_list|,
name|unit
argument_list|,
name|vs
operator|->
name|vs_olen
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"vvdriver vs_olen botch"
argument_list|)
expr_stmt|;
block|}
name|vs
operator|->
name|vs_if
operator|.
name|if_timer
operator|=
name|VVTIMEOUT
expr_stmt|;
name|vs
operator|->
name|vs_oactive
operator|=
literal|1
expr_stmt|;
comment|/* ship it */
if|if
condition|(
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_flags
operator|&
name|UBA_NEEDBDP
condition|)
name|UBAPURGE
argument_list|(
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_uba
argument_list|,
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_w
operator|.
name|ifrw_bdp
argument_list|)
expr_stmt|;
name|addr
operator|=
operator|(
expr|struct
name|vvreg
operator|*
operator|)
name|ui
operator|->
name|ui_addr
expr_stmt|;
name|ubainfo
operator|=
name|vs
operator|->
name|vs_ifuba
operator|.
name|ifu_w
operator|.
name|ifrw_info
expr_stmt|;
name|addr
operator|->
name|vvoba
operator|=
operator|(
name|u_short
operator|)
name|ubainfo
expr_stmt|;
name|addr
operator|->
name|vvoea
operator|=
call|(
name|u_short
call|)
argument_list|(
name|ubainfo
operator|>>
literal|16
argument_list|)
expr_stmt|;
name|addr
operator|->
name|vvowc
operator|=
operator|-
operator|(
operator|(
name|vs
operator|->
name|vs_olen
operator|+
literal|1
operator|)
operator|>>
literal|1
operator|)
expr_stmt|;
name|addr
operator|->
name|vvowc
operator|=
operator|-
operator|(
operator|(
name|vs
operator|->
name|vs_olen
operator|+
literal|1
operator|)
operator|>>
literal|1
operator|)
expr_stmt|;
comment|/* extra byte is garbage */
if|if
condition|(
name|addr
operator|->
name|vvocsr
operator|&
name|VV_NOK
condition|)
name|vs
operator|->
name|vs_init
operator|++
expr_stmt|;
comment|/* count ring inits */
name|addr
operator|->
name|vvocsr
operator|=
name|VV_IEN
operator||
name|VV_CPB
operator||
name|VV_DEN
operator||
name|VV_INR
operator||
name|VV_ENB
expr_stmt|;
name|vs
operator|->
name|vs_if
operator|.
name|if_timer
operator|=
name|VVTIMEOUT
expr_stmt|;
name|vs
operator|->
name|vs_oactive
operator|=
literal|1
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * proNET transmit interrupt  * Start another output if more data to send.  */
end_comment

begin_macro
name|vvxint
argument_list|(
argument|unit
argument_list|)
end_macro

begin_decl_stmt
name|int
name|unit
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
specifier|register
name|struct
name|vv_softc
modifier|*
name|vs
decl_stmt|;
specifier|register
name|struct
name|vvreg
modifier|*
name|addr
decl_stmt|;
specifier|register
name|int
name|oc
decl_stmt|;
name|ui
operator|=
name|vvinfo
index|[
name|unit
index|]
expr_stmt|;
name|vs
operator|=
operator|&
name|vv_softc
index|[
name|unit
index|]
expr_stmt|;
name|vs
operator|->
name|vs_if
operator|.
name|if_timer
operator|=
literal|0
expr_stmt|;
name|addr
operator|=
operator|(
expr|struct
name|vvreg
operator|*
operator|)
name|ui
operator|->
name|ui_addr
expr_stmt|;
name|oc
operator|=
literal|0xffff
operator|&
operator|(
name|addr
operator|->
name|vvocsr
operator|)
expr_stmt|;
if|if
condition|(
name|vs
operator|->
name|vs_oactive
operator|==
literal|0
condition|)
block|{
name|vvprintf
argument_list|(
literal|"vv%d: stray interrupt vvocsr = %b\n"
argument_list|,
name|unit
argument_list|,
name|oc
argument_list|,
name|VV_OBITS
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * we retransmit on soft error 	 * TODO: sort retransmits to end of queue if possible! 	 */
if|if
condition|(
name|oc
operator|&
operator|(
name|VV_OPT
operator||
name|VV_RFS
operator|)
condition|)
block|{
if|if
condition|(
name|vs
operator|->
name|vs_tries
operator|++
operator|<
name|VVRETRY
condition|)
block|{
if|if
condition|(
name|oc
operator|&
name|VV_OPT
condition|)
name|vs
operator|->
name|vs_otimeout
operator|++
expr_stmt|;
if|if
condition|(
name|oc
operator|&
name|VV_RFS
condition|)
block|{
name|vs
operator|->
name|vs_if
operator|.
name|if_collisions
operator|++
expr_stmt|;
name|vs
operator|->
name|vs_refused
operator|++
expr_stmt|;
block|}
name|vvstart
argument_list|(
name|unit
argument_list|)
expr_stmt|;
comment|/* restart this message */
return|return;
block|}
block|}
name|vs
operator|->
name|vs_if
operator|.
name|if_opackets
operator|++
expr_stmt|;
name|vs
operator|->
name|vs_oactive
operator|=
literal|0
expr_stmt|;
name|vs
operator|->
name|vs_tries
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|oc
operator|&
name|VVXERR
condition|)
block|{
name|vs
operator|->
name|vs_if
operator|.
name|if_oerrors
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"vv%d: error vvocsr = %b\n"
argument_list|,
argument|unit
argument_list|,
literal|0xffff
argument|& oc
argument_list|,
argument|vvprintf(
literal|"vv%d: error vvocsr = %b\n"
argument|, unit,
literal|0xffff
argument|& oc, 		    VV_OBITS); 	} 	if (vs->vs_ifuba.ifu_xtofree) { 		m_freem(vs->vs_ifuba.ifu_xtofree); 		vs->vs_ifuba.ifu_xtofree =
literal|0
argument|; 	} 	vvstart(unit); }
comment|/*  * Transmit watchdog timer routine.  * This routine gets called when we lose a transmit interrupt.  * The best we can do is try to restart output.  */
argument|vvwatchdog(unit) 	int unit; { 	register struct vv_softc *vs; 	register int s;  	vs =&vv_softc[unit]; 	vvprintf(
literal|"vv%d: lost a transmit interrupt.\n"
argument|, unit); 	vs->vs_timeouts++; 	s = splimp(); 	vvstart(unit); 	splx(s); }
comment|/*  * proNET interface receiver interrupt.  * If input error just drop packet.  * Otherwise purge input buffered data path and examine  * packet to determine type.  If can't determine length  * from type, then have to drop packet.  Otherwise decapsulate  * packet based on type and pass to type specific higher-level  * input routine.  */
argument|vvrint(unit) 	int unit; { 	register struct vv_softc *vs; 	register struct vvreg *addr; 	register struct vv_header *vv; 	register struct ifqueue *inq; 	register struct mbuf *m; 	int ubainfo
argument_list|,
argument|len
argument_list|,
argument|off
argument_list|,
argument|s; 	short resid;  	vs =&vv_softc[unit]; 	vs->vs_if.if_ipackets++; 	addr = (struct vvreg *)vvinfo[unit]->ui_addr;
comment|/* 	 * Purge BDP; drop if input error indicated. 	 */
argument|if (vs->vs_ifuba.ifu_flags& UBA_NEEDBDP) 		UBAPURGE(vs->vs_ifuba.ifu_uba, vs->vs_ifuba.ifu_r.ifrw_bdp);
comment|/* 	 * receive errors? 	 */
argument|if (addr->vvicsr& VVRERR) { 		vvprintf(
literal|"vv%d: receive error, vvicsr = %b\n"
argument|, unit,
literal|0xffff
argument|&(addr->vvicsr), VV_IBITS); 		if (addr->vvicsr& VV_BDF) 			vs->vs_ibadf++; 		goto dropit; 	}
comment|/* 	 * parity errors? 	 */
argument|if (addr->vvicsr& VV_LDE) {
comment|/* we don't have to clear it because the receive command */
comment|/* writes 0 to parity bit */
argument|vs->vs_parity++;
ifndef|#
directive|ifndef
name|PRONET80
comment|/* 		 * only on 10 megabit proNET is VV_LDE an end-to-end parity 		 * bit. On 80 megabit, it returns to the intended use of 		 * node-to-node parity. End-to-end parity errors on 80 megabit 		 * give VV_BDF. 		 */
argument|goto dropit;
endif|#
directive|endif
argument|}
comment|/* 	 * Get packet length from residual word count 	 * 	 * Compute header offset if trailer protocol 	 * 	 * Pull packet off interface.  Off is nonzero if packet 	 * has trailing header; if_rubaget will then force this header 	 * information to be at the front.  The vh_info field 	 * carries the offset to the trailer data in trailer 	 * format packets. 	 */
argument|vv = (struct vv_header *)(vs->vs_ifuba.ifu_r.ifrw_addr); 	vvtracehdr(
literal|"vi"
argument|, vv); 	resid = addr->vviwc&
literal|01777
argument|;
comment|/* only low 10 bits valid */
argument|if (resid) 		resid |=
literal|0176000
argument|;
comment|/* high 6 bits are undefined */
argument|len = ((VVBUFSIZE>>
literal|1
argument|) + resid)<<
literal|1
argument|; 	len -= sizeof(struct vv_header);  	if ((addr->vvicsr& VV_DPR) || len> VVMRU || len<=
literal|0
argument|) { 		vvprintf(
literal|"vv%d: len too long or short, \ len = %d, vvicsr = %b\n"
argument|, 			    unit, len,
literal|0xffff
argument|&(addr->vvicsr), VV_IBITS); 		goto dropit; 	}
comment|/* check the protocol header version */
argument|if (vv->vh_version != RING_VERSION) { 		vvprintf(
literal|"vv%d: bad protocol header version %d\n"
argument|, 		    unit, vv->vh_version&
literal|0xff
argument|); 		goto dropit; 	}
define|#
directive|define
name|vvdataaddr
parameter_list|(
name|vv
parameter_list|,
name|off
parameter_list|,
name|type
parameter_list|)
value|((type)(((caddr_t)((vv)+1)+(off))))
argument|if (vv->vh_type>= RING_IPTrailer&& 	     vv->vh_type< RING_IPTrailer+RING_IPNTrailer) { 		off = (vv->vh_type - RING_IPTrailer) *
literal|512
argument|; 		if (off> VVMTU) { 			vvprintf(
literal|"vv%d: off> VVMTU, off = %d, vvicsr = %b\n"
argument|, 				    unit, off,
literal|0xffff
argument|&(addr->vvicsr), VV_IBITS); 			goto dropit; 		} 		vv->vh_type = *vvdataaddr(vv, off, u_short *); 		resid = *(vvdataaddr(vv, off+
literal|2
argument|, u_short *)); 		if (off + resid> len) { 			vvprintf(
literal|"vv%d: trailer packet too short\n"
argument|, unit); 			vvprintf(
literal|"vv%d: off = %d, resid = %d, vvicsr = %b\n"
argument|, 				    unit, off, resid,
literal|0xffff
argument|&(addr->vvicsr), VV_IBITS); 			goto dropit; 		} 		len = off + resid; 	} else 		off =
literal|0
argument|;  	if (len ==
literal|0
argument|) { 		vvprintf(
literal|"vv%d: len is zero, vvicsr = %b\n"
argument|, unit,
literal|0xffff
argument|&(addr->vvicsr), VV_IBITS); 		goto dropit; 	}  	m = if_rubaget(&vs->vs_ifuba, len, off); 	if (m == NULL) { 		vvprintf(
literal|"vv%d: if_rubaget() failed, vvicsr = %b\n"
argument|, unit,
literal|0xffff
argument|&(addr->vvicsr), VV_IBITS); 		goto dropit; 	} 	if (off) { 		m->m_off +=
literal|2
argument|* sizeof(u_short); 		m->m_len -=
literal|2
argument|* sizeof(u_short); 	}
comment|/* Keep track of source address of this packet */
argument|vs->vs_lastr = vv->vh_shost;
comment|/* 	 * Demultiplex on packet type 	 */
argument|switch (vv->vh_type) {
ifdef|#
directive|ifdef
name|INET
argument|case RING_IP: 		schednetisr(NETISR_IP); 		inq =&ipintrq; 		break;
endif|#
directive|endif
argument|default: 		vvprintf(
literal|"vv%d: unknown pkt type 0x%x\n"
argument|, unit, vv->vh_type); 		m_freem(m); 		goto setup; 	} 	s = splimp(); 	if (IF_QFULL(inq)) { 		IF_DROP(inq); 		m_freem(m); 	} else 		IF_ENQUEUE(inq, m);  	splx(s);
comment|/* 	 * Reset for the next packet. 	 */
argument|setup: 	ubainfo = vs->vs_ifuba.ifu_r.ifrw_info; 	addr->vviba = (u_short) ubainfo; 	addr->vviea = (u_short) (ubainfo>>
literal|16
argument|); 	addr->vviwc = -(VVBUFSIZE)>>
literal|1
argument|; 	addr->vvicsr = VV_HEN | VV_IEN | VV_DEN | VV_ENB; 	return;
comment|/* 	 * Drop packet on floor -- count them!! 	 */
argument|dropit: 	vs->vs_if.if_ierrors++; 	goto setup; }
comment|/*  * proNET output routine.  * Encapsulate a packet of type family for the local net.  * Use trailer local net encapsulation if enough data in first  * packet leaves a multiple of 512 bytes of data in remainder.  */
argument|vvoutput(ifp, m0, dst) 	struct ifnet *ifp; 	struct mbuf *m0; 	struct sockaddr *dst; { 	register struct mbuf *m; 	register struct vv_header *vv; 	register int off; 	register int unit; 	register struct vvreg *addr; 	register struct vv_softc *vs; 	register int s; 	int type
argument_list|,
argument|dest
argument_list|,
argument|error;  	m = m0; 	unit = ifp->if_unit; 	addr = (struct vvreg *)vvinfo[unit]->ui_addr; 	vs =&vv_softc[unit];
comment|/* 	 * Check to see if the input side has wedged due the UBA 	 * vectoring through 0. 	 * 	 * We are lower than device ipl when we enter this routine, 	 * so if the interface is ready with an input packet then 	 * an input interrupt must have slipped through the cracks. 	 * 	 * Avoid the race with an input interrupt by watching to see 	 * if any packets come in. 	 */
argument|s = vs->vs_if.if_ipackets; 	if (addr->vvicsr& VV_RDY&& s == vs->vs_if.if_ipackets) { 		vvprintf(
literal|"vv%d: lost a receive interrupt, icsr = %b\n"
argument|, 			    unit,
literal|0xffff
argument|&(addr->vvicsr), VV_IBITS); 		s = splimp(); 		vvrint(unit); 		splx(s); 	}  	switch (dst->sa_family) {
ifdef|#
directive|ifdef
name|INET
argument|case AF_INET: 		dest = ((struct sockaddr_in *)dst)->sin_addr.s_addr;
ifdef|#
directive|ifdef
name|LOOPBACK
argument|if ((dest == ((struct sockaddr_in *)&ifp->if_addr)->sin_addr.s_addr)&& 		   ((loif.if_flags& IFF_UP) !=
literal|0
argument|)) 			return(looutput(&loif, m0, dst));
endif|#
directive|endif
endif|LOOPBACK
argument|if ((dest = in_lnaof(*((struct in_addr *)&dest)))>=
literal|0x100
argument|) { 			error = EPERM; 			goto bad; 		} 		off = ntohs((u_short)mtod(m, struct ip *)->ip_len) - m->m_len;
comment|/* 		 * Trailerize, if the configuration allows it. 		 * TODO: Need per host negotiation. 		 */
argument|if ((ifp->if_flags& IFF_NOTRAILERS) ==
literal|0
argument|) 		if (off>
literal|0
argument|&& (off&
literal|0x1ff
argument|) ==
literal|0
argument|&& 		    m->m_off>= MMINOFF +
literal|2
argument|* sizeof (u_short)) { 			type = RING_IPTrailer + (off>>
literal|9
argument|); 			m->m_off -=
literal|2
argument|* sizeof (u_short); 			m->m_len +=
literal|2
argument|* sizeof (u_short); 			*mtod(m, u_short *) = RING_IP; 			*(mtod(m, u_short *) +
literal|1
argument|) = m->m_len; 			goto gottrailertype; 		} 		type = RING_IP; 		off =
literal|0
argument|; 		goto gottype;
endif|#
directive|endif
argument|default: 		printf(
literal|"vv%d: can't handle af%d\n"
argument|, unit, dst->sa_family); 		error = EAFNOSUPPORT; 		goto bad; 	}  gottrailertype:
comment|/* 	 * Packet to be sent as trailer: move first packet 	 * (control information) to end of chain. 	 */
argument|while (m->m_next) 		m = m->m_next; 	m->m_next = m0; 	m = m0->m_next; 	m0->m_next =
literal|0
argument|; 	m0 = m; gottype:
comment|/* 	 * Add local net header.  If no space in first mbuf, 	 * allocate another. 	 */
argument|if (m->m_off> MMAXOFF || 	    MMINOFF + sizeof (struct vv_header)> m->m_off) { 		m = m_get(M_DONTWAIT, MT_HEADER); 		if (m == NULL) { 			error = ENOBUFS; 			goto bad; 		} 		m->m_next = m0; 		m->m_off = MMINOFF; 		m->m_len = sizeof (struct vv_header); 	} else { 		m->m_off -= sizeof (struct vv_header); 		m->m_len += sizeof (struct vv_header); 	} 	vv = mtod(m, struct vv_header *); 	vv->vh_shost = ifp->if_host[
literal|0
argument|];
comment|/* Map the destination address if it's a broadcast */
argument|if ((vv->vh_dhost = dest) == INADDR_ANY) 		vv->vh_dhost = VV_BROADCAST; 	vv->vh_version = RING_VERSION; 	vv->vh_type = type; 	vv->vh_info = off; 	vvtracehdr(
literal|"vo"
argument|, vv);
comment|/* 	 * Queue message on interface, and start output if interface 	 * not yet active. 	 */
argument|s = splimp(); 	if (IF_QFULL(&ifp->if_snd)) { 		IF_DROP(&ifp->if_snd); 		error = ENOBUFS; 		goto qfull; 	} 	IF_ENQUEUE(&ifp->if_snd, m); 	if (vs->vs_oactive ==
literal|0
argument|) 		vvstart(unit); 	splx(s); 	return (
literal|0
argument|); qfull: 	m0 = m; 	splx(s); bad: 	m_freem(m0); 	return(error); }
comment|/*  * Process an ioctl request.  */
argument|vvioctl(ifp, cmd, data) 	register struct ifnet *ifp; 	int cmd; 	caddr_t data; { 	register struct ifreq *ifr; 	register int s; 	int error;  	ifr = (struct ifreq *)data; 	error =
literal|0
argument|; 	s = splimp(); 	switch (cmd) {  	case SIOCSIFADDR: 		if (ifp->if_flags& IFF_RUNNING) 			if_rtinit(ifp, -
literal|1
argument|);
comment|/* delete previous route */
argument|vvsetaddr(ifp, (struct sockaddr_in *)&ifr->ifr_addr); 		if (ifp->if_flags& IFF_RUNNING) 			if_rtinit(ifp, RTF_UP); 		else 			vvinit(ifp->if_unit); 		break;  	default: 		error = EINVAL; 	} 	splx(s); 	return(error); }
comment|/*  * Set up the address for this interface. We use the network number  * from the passed address and an invalid host number; vvinit() will  * figure out the host number and insert it later.  */
argument|vvsetaddr(ifp, sin) 	register struct ifnet *ifp; 	register struct sockaddr_in *sin; { 	ifp->if_net = in_netof(sin->sin_addr); 	ifp->if_host[
literal|0
argument|] =
literal|256
argument|;
comment|/* an invalid host number */
argument|sin = (struct sockaddr_in *)&ifp->if_addr; 	sin->sin_family = AF_INET; 	sin->sin_addr = if_makeaddr(ifp->if_net, ifp->if_host[
literal|0
argument|]); 	sin = (struct sockaddr_in *)&ifp->if_broadaddr; 	sin->sin_family = AF_INET; 	sin->sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY); 	ifp->if_flags |= IFF_BROADCAST; }
comment|/*  * vvprt_hdr(s, v) print the local net header in "v"  *	with title is "s"  */
argument|vvprt_hdr(s, v) 	char *s; 	register struct vv_header *v; { 	printf(
literal|"%s: dsvti: 0x%x 0x%x 0x%x 0x%x 0x%x\n"
argument|, 		s,
literal|0xff
argument|& (int)(v->vh_dhost),
literal|0xff
argument|& (int)(v->vh_shost),
literal|0xff
argument|& (int)(v->vh_version),
literal|0xff
argument|& (int)(v->vh_type),
literal|0xffff
argument|& (int)(v->vh_info)); }
end_block

end_unit

