begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent code for the i386.     Copyright 2001, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"breakpoint.h"
end_include

begin_include
include|#
directive|include
file|"command.h"
end_include

begin_include
include|#
directive|include
file|"gdbcmd.h"
end_include

begin_comment
comment|/* Support for hardware watchpoints and breakpoints using the i386    debug registers.     This provides several functions for inserting and removing    hardware-assisted breakpoints and watchpoints, testing if one or    more of the watchpoints triggered and at what address, checking    whether a given region can be watched, etc.     A target which wants to use these functions should define several    macros, such as `target_insert_watchpoint' and    `target_stopped_data_address', listed in target.h, to call the    appropriate functions below.  It should also define    I386_USE_GENERIC_WATCHPOINTS in its tm.h file.     In addition, each target should provide several low-level macros    that will be called to insert watchpoints and hardware breakpoints    into the inferior, remove them, and check their status.  These    macros are:        I386_DR_LOW_SET_CONTROL  -- set the debug control (DR7) 				  register to a given value        I386_DR_LOW_SET_ADDR     -- put an address into one debug 				  register        I386_DR_LOW_RESET_ADDR   -- reset the address stored in 				  one debug register        I386_DR_LOW_GET_STATUS   -- return the value of the debug 				  status (DR6) register.     The functions below implement debug registers sharing by reference    counts, and allow to watch regions up to 16 bytes long.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I386_USE_GENERIC_WATCHPOINTS
end_ifdef

begin_comment
comment|/* Support for 8-byte wide hw watchpoints.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_HAS_DR_LEN_8
end_ifndef

begin_define
define|#
directive|define
name|TARGET_HAS_DR_LEN_8
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Debug registers' indices.  */
end_comment

begin_define
define|#
directive|define
name|DR_NADDR
value|4
end_define

begin_comment
comment|/* The number of debug address registers.  */
end_comment

begin_define
define|#
directive|define
name|DR_STATUS
value|6
end_define

begin_comment
comment|/* Index of debug status register (DR6).  */
end_comment

begin_define
define|#
directive|define
name|DR_CONTROL
value|7
end_define

begin_comment
comment|/* Index of debug control register (DR7). */
end_comment

begin_comment
comment|/* DR7 Debug Control register fields.  */
end_comment

begin_comment
comment|/* How many bits to skip in DR7 to get to R/W and LEN fields.  */
end_comment

begin_define
define|#
directive|define
name|DR_CONTROL_SHIFT
value|16
end_define

begin_comment
comment|/* How many bits in DR7 per R/W and LEN field for each watchpoint.  */
end_comment

begin_define
define|#
directive|define
name|DR_CONTROL_SIZE
value|4
end_define

begin_comment
comment|/* Watchpoint/breakpoint read/write fields in DR7.  */
end_comment

begin_define
define|#
directive|define
name|DR_RW_EXECUTE
value|(0x0)
end_define

begin_comment
comment|/* Break on instruction execution.  */
end_comment

begin_define
define|#
directive|define
name|DR_RW_WRITE
value|(0x1)
end_define

begin_comment
comment|/* Break on data writes.  */
end_comment

begin_define
define|#
directive|define
name|DR_RW_READ
value|(0x3)
end_define

begin_comment
comment|/* Break on data reads or writes.  */
end_comment

begin_comment
comment|/* This is here for completeness.  No platform supports this    functionality yet (as of March 2001).  Note that the DE flag in the    CR4 register needs to be set to support this.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DR_RW_IORW
end_ifndef

begin_define
define|#
directive|define
name|DR_RW_IORW
value|(0x2)
end_define

begin_comment
comment|/* Break on I/O reads or writes.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Watchpoint/breakpoint length fields in DR7.  The 2-bit left shift    is so we could OR this with the read/write field defined above.  */
end_comment

begin_define
define|#
directive|define
name|DR_LEN_1
value|(0x0<< 2)
end_define

begin_comment
comment|/* 1-byte region watch or breakpoint.  */
end_comment

begin_define
define|#
directive|define
name|DR_LEN_2
value|(0x1<< 2)
end_define

begin_comment
comment|/* 2-byte region watch.  */
end_comment

begin_define
define|#
directive|define
name|DR_LEN_4
value|(0x3<< 2)
end_define

begin_comment
comment|/* 4-byte region watch.  */
end_comment

begin_define
define|#
directive|define
name|DR_LEN_8
value|(0x2<< 2)
end_define

begin_comment
comment|/* 8-byte region watch (AMD64).  */
end_comment

begin_comment
comment|/* Local and Global Enable flags in DR7.     When the Local Enable flag is set, the breakpoint/watchpoint is    enabled only for the current task; the processor automatically    clears this flag on every task switch.  When the Global Enable flag    is set, the breakpoint/watchpoint is enabled for all tasks; the    processor never clears this flag.     Currently, all watchpoint are locally enabled.  If you need to    enable them globally, read the comment which pertains to this in    i386_insert_aligned_watchpoint below.  */
end_comment

begin_define
define|#
directive|define
name|DR_LOCAL_ENABLE_SHIFT
value|0
end_define

begin_comment
comment|/* Extra shift to the local enable bit.  */
end_comment

begin_define
define|#
directive|define
name|DR_GLOBAL_ENABLE_SHIFT
value|1
end_define

begin_comment
comment|/* Extra shift to the global enable bit.  */
end_comment

begin_define
define|#
directive|define
name|DR_ENABLE_SIZE
value|2
end_define

begin_comment
comment|/* Two enable bits per debug register.  */
end_comment

begin_comment
comment|/* Local and global exact breakpoint enable flags (a.k.a. slowdown    flags).  These are only required on i386, to allow detection of the    exact instruction which caused a watchpoint to break; i486 and    later processors do that automatically.  We set these flags for    backwards compatibility.  */
end_comment

begin_define
define|#
directive|define
name|DR_LOCAL_SLOWDOWN
value|(0x100)
end_define

begin_define
define|#
directive|define
name|DR_GLOBAL_SLOWDOWN
value|(0x200)
end_define

begin_comment
comment|/* Fields reserved by Intel.  This includes the GD (General Detect    Enable) flag, which causes a debug exception to be generated when a    MOV instruction accesses one of the debug registers.     FIXME: My Intel manual says we should use 0xF800, not 0xFC00.  */
end_comment

begin_define
define|#
directive|define
name|DR_CONTROL_RESERVED
value|(0xFC00)
end_define

begin_comment
comment|/* Auxiliary helper macros.  */
end_comment

begin_comment
comment|/* A value that masks all fields in DR7 that are reserved by Intel.  */
end_comment

begin_define
define|#
directive|define
name|I386_DR_CONTROL_MASK
value|(~DR_CONTROL_RESERVED)
end_define

begin_comment
comment|/* The I'th debug register is vacant if its Local and Global Enable    bits are reset in the Debug Control register.  */
end_comment

begin_define
define|#
directive|define
name|I386_DR_VACANT
parameter_list|(
name|i
parameter_list|)
define|\
value|((dr_control_mirror& (3<< (DR_ENABLE_SIZE * (i)))) == 0)
end_define

begin_comment
comment|/* Locally enable the break/watchpoint in the I'th debug register.  */
end_comment

begin_define
define|#
directive|define
name|I386_DR_LOCAL_ENABLE
parameter_list|(
name|i
parameter_list|)
define|\
value|dr_control_mirror |= (1<< (DR_LOCAL_ENABLE_SHIFT + DR_ENABLE_SIZE * (i)))
end_define

begin_comment
comment|/* Globally enable the break/watchpoint in the I'th debug register.  */
end_comment

begin_define
define|#
directive|define
name|I386_DR_GLOBAL_ENABLE
parameter_list|(
name|i
parameter_list|)
define|\
value|dr_control_mirror |= (1<< (DR_GLOBAL_ENABLE_SHIFT + DR_ENABLE_SIZE * (i)))
end_define

begin_comment
comment|/* Disable the break/watchpoint in the I'th debug register.  */
end_comment

begin_define
define|#
directive|define
name|I386_DR_DISABLE
parameter_list|(
name|i
parameter_list|)
define|\
value|dr_control_mirror&= ~(3<< (DR_ENABLE_SIZE * (i)))
end_define

begin_comment
comment|/* Set in DR7 the RW and LEN fields for the I'th debug register.  */
end_comment

begin_define
define|#
directive|define
name|I386_DR_SET_RW_LEN
parameter_list|(
name|i
parameter_list|,
name|rwlen
parameter_list|)
define|\
value|do { \     dr_control_mirror&= ~(0x0f<< (DR_CONTROL_SHIFT+DR_CONTROL_SIZE*(i)));   \     dr_control_mirror |= ((rwlen)<< (DR_CONTROL_SHIFT+DR_CONTROL_SIZE*(i))); \   } while (0)
end_define

begin_comment
comment|/* Get from DR7 the RW and LEN fields for the I'th debug register.  */
end_comment

begin_define
define|#
directive|define
name|I386_DR_GET_RW_LEN
parameter_list|(
name|i
parameter_list|)
define|\
value|((dr_control_mirror>> (DR_CONTROL_SHIFT + DR_CONTROL_SIZE * (i)))& 0x0f)
end_define

begin_comment
comment|/* Did the watchpoint whose address is in the I'th register break?  */
end_comment

begin_define
define|#
directive|define
name|I386_DR_WATCH_HIT
parameter_list|(
name|i
parameter_list|)
value|(dr_status_mirror& (1<< (i)))
end_define

begin_comment
comment|/* A macro to loop over all debug registers.  */
end_comment

begin_define
define|#
directive|define
name|ALL_DEBUG_REGISTERS
parameter_list|(
name|i
parameter_list|)
value|for (i = 0; i< DR_NADDR; i++)
end_define

begin_comment
comment|/* Mirror the inferior's DRi registers.  We keep the status and    control registers separated because they don't hold addresses.  */
end_comment

begin_decl_stmt
specifier|static
name|CORE_ADDR
name|dr_mirror
index|[
name|DR_NADDR
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|dr_status_mirror
decl_stmt|,
name|dr_control_mirror
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reference counts for each debug register.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|dr_ref_count
index|[
name|DR_NADDR
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether or not to print the mirrored debug registers.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|maint_show_dr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Types of operations supported by i386_handle_nonaligned_watchpoint.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|WP_INSERT
block|,
name|WP_REMOVE
block|,
name|WP_COUNT
block|}
name|i386_wp_op_t
typedef|;
end_typedef

begin_comment
comment|/* Internal functions.  */
end_comment

begin_comment
comment|/* Return the value of a 4-bit field for DR7 suitable for watching a    region of LEN bytes for accesses of type TYPE.  LEN is assumed to    have the value of 1, 2, or 4.  */
end_comment

begin_function_decl
specifier|static
name|unsigned
name|i386_length_and_rw_bits
parameter_list|(
name|int
name|len
parameter_list|,
name|enum
name|target_hw_bp_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Insert a watchpoint at address ADDR, which is assumed to be aligned    according to the length of the region to watch.  LEN_RW_BITS is the    value of the bit-field from DR7 which describes the length and    access type of the region to be watched by this watchpoint.  Return    0 on success, -1 on failure.  */
end_comment

begin_function_decl
specifier|static
name|int
name|i386_insert_aligned_watchpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|unsigned
name|len_rw_bits
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Remove a watchpoint at address ADDR, which is assumed to be aligned    according to the length of the region to watch.  LEN_RW_BITS is the    value of the bits from DR7 which describes the length and access    type of the region watched by this watchpoint.  Return 0 on    success, -1 on failure.  */
end_comment

begin_function_decl
specifier|static
name|int
name|i386_remove_aligned_watchpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|unsigned
name|len_rw_bits
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Insert or remove a (possibly non-aligned) watchpoint, or count the    number of debug registers required to watch a region at address    ADDR whose length is LEN for accesses of type TYPE.  Return 0 on    successful insertion or removal, a positive number when queried    about the number of registers, or -1 on failure.  If WHAT is not a    valid value, bombs through internal_error.  */
end_comment

begin_function_decl
specifier|static
name|int
name|i386_handle_nonaligned_watchpoint
parameter_list|(
name|i386_wp_op_t
name|what
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|,
name|int
name|len
parameter_list|,
name|enum
name|target_hw_bp_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Implementation.  */
end_comment

begin_comment
comment|/* Clear the reference counts and forget everything we knew about the    debug registers.  */
end_comment

begin_function
name|void
name|i386_cleanup_dregs
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|ALL_DEBUG_REGISTERS
argument_list|(
argument|i
argument_list|)
block|{
name|dr_mirror
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|dr_ref_count
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
name|dr_control_mirror
operator|=
literal|0
expr_stmt|;
name|dr_status_mirror
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_CHILD_POST_STARTUP_INFERIOR
end_ifndef

begin_comment
comment|/* Reset all debug registers at each new startup to avoid missing    watchpoints after restart.  */
end_comment

begin_function
name|void
name|child_post_startup_inferior
parameter_list|(
name|ptid_t
name|ptid
parameter_list|)
block|{
name|i386_cleanup_dregs
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LINUX_CHILD_POST_STARTUP_INFERIOR */
end_comment

begin_comment
comment|/* Print the values of the mirrored debug registers.  This is called    when maint_show_dr is non-zero.  To set that up, type "maint    show-debug-regs" at GDB's prompt.  */
end_comment

begin_function
specifier|static
name|void
name|i386_show_dr
parameter_list|(
specifier|const
name|char
modifier|*
name|func
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|,
name|int
name|len
parameter_list|,
name|enum
name|target_hw_bp_type
name|type
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|puts_unfiltered
argument_list|(
name|func
argument_list|)
expr_stmt|;
if|if
condition|(
name|addr
operator|||
name|len
condition|)
name|printf_unfiltered
argument_list|(
literal|" (addr=%lx, len=%d, type=%s)"
argument_list|,
comment|/* This code is for ia32, so casting CORE_ADDR 			  to unsigned long should be okay.  */
operator|(
name|unsigned
name|long
operator|)
name|addr
argument_list|,
name|len
argument_list|,
name|type
operator|==
name|hw_write
condition|?
literal|"data-write"
else|:
operator|(
name|type
operator|==
name|hw_read
condition|?
literal|"data-read"
else|:
operator|(
name|type
operator|==
name|hw_access
condition|?
literal|"data-read/write"
else|:
operator|(
name|type
operator|==
name|hw_execute
condition|?
literal|"instruction-execute"
comment|/* FIXME: if/when I/O read/write 				   watchpoints are supported, add them 				   here.  */
else|:
literal|"??unknown??"
operator|)
operator|)
operator|)
argument_list|)
expr_stmt|;
name|puts_unfiltered
argument_list|(
literal|":\n"
argument_list|)
expr_stmt|;
name|printf_unfiltered
argument_list|(
literal|"\tCONTROL (DR7): %08x          STATUS (DR6): %08x\n"
argument_list|,
name|dr_control_mirror
argument_list|,
name|dr_status_mirror
argument_list|)
expr_stmt|;
name|ALL_DEBUG_REGISTERS
argument_list|(
argument|i
argument_list|)
block|{
name|printf_unfiltered
argument_list|(
literal|"\ \tDR%d: addr=0x%s, ref.count=%d  DR%d: addr=0x%s, ref.count=%d\n"
argument_list|,
name|i
argument_list|,
name|paddr
argument_list|(
name|dr_mirror
index|[
name|i
index|]
argument_list|)
argument_list|,
name|dr_ref_count
index|[
name|i
index|]
argument_list|,
name|i
operator|+
literal|1
argument_list|,
name|paddr
argument_list|(
name|dr_mirror
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
argument_list|,
name|dr_ref_count
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
name|i
operator|++
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* Return the value of a 4-bit field for DR7 suitable for watching a    region of LEN bytes for accesses of type TYPE.  LEN is assumed to    have the value of 1, 2, or 4.  */
end_comment

begin_function
specifier|static
name|unsigned
name|i386_length_and_rw_bits
parameter_list|(
name|int
name|len
parameter_list|,
name|enum
name|target_hw_bp_type
name|type
parameter_list|)
block|{
name|unsigned
name|rw
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|hw_execute
case|:
name|rw
operator|=
name|DR_RW_EXECUTE
expr_stmt|;
break|break;
case|case
name|hw_write
case|:
name|rw
operator|=
name|DR_RW_WRITE
expr_stmt|;
break|break;
case|case
name|hw_read
case|:
comment|/* The i386 doesn't support data-read watchpoints.  */
case|case
name|hw_access
case|:
name|rw
operator|=
name|DR_RW_READ
expr_stmt|;
break|break;
if|#
directive|if
literal|0
comment|/* Not yet supported.  */
block|case hw_io_access: 	rw = DR_RW_IORW; 	break;
endif|#
directive|endif
default|default:
name|internal_error
argument_list|(
name|__FILE__
argument_list|,
name|__LINE__
argument_list|,
literal|"\ Invalid hardware breakpoint type %d in i386_length_and_rw_bits.\n"
argument_list|,
operator|(
name|int
operator|)
name|type
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|len
condition|)
block|{
case|case
literal|1
case|:
return|return
operator|(
name|DR_LEN_1
operator||
name|rw
operator|)
return|;
case|case
literal|2
case|:
return|return
operator|(
name|DR_LEN_2
operator||
name|rw
operator|)
return|;
case|case
literal|4
case|:
return|return
operator|(
name|DR_LEN_4
operator||
name|rw
operator|)
return|;
case|case
literal|8
case|:
if|if
condition|(
name|TARGET_HAS_DR_LEN_8
condition|)
return|return
operator|(
name|DR_LEN_8
operator||
name|rw
operator|)
return|;
default|default:
name|internal_error
argument_list|(
name|__FILE__
argument_list|,
name|__LINE__
argument_list|,
literal|"\ Invalid hardware breakpoint length %d in i386_length_and_rw_bits.\n"
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* Insert a watchpoint at address ADDR, which is assumed to be aligned    according to the length of the region to watch.  LEN_RW_BITS is the    value of the bits from DR7 which describes the length and access    type of the region to be watched by this watchpoint.  Return 0 on    success, -1 on failure.  */
end_comment

begin_function
specifier|static
name|int
name|i386_insert_aligned_watchpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|unsigned
name|len_rw_bits
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
comment|/* First, look for an occupied debug register with the same address      and the same RW and LEN definitions.  If we find one, we can      reuse it for this watchpoint as well (and save a register).  */
name|ALL_DEBUG_REGISTERS
argument_list|(
argument|i
argument_list|)
block|{
if|if
condition|(
operator|!
name|I386_DR_VACANT
argument_list|(
name|i
argument_list|)
operator|&&
name|dr_mirror
index|[
name|i
index|]
operator|==
name|addr
operator|&&
name|I386_DR_GET_RW_LEN
argument_list|(
name|i
argument_list|)
operator|==
name|len_rw_bits
condition|)
block|{
name|dr_ref_count
index|[
name|i
index|]
operator|++
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
comment|/* Next, look for a vacant debug register.  */
name|ALL_DEBUG_REGISTERS
argument_list|(
argument|i
argument_list|)
block|{
if|if
condition|(
name|I386_DR_VACANT
argument_list|(
name|i
argument_list|)
condition|)
break|break;
block|}
comment|/* No more debug registers!  */
if|if
condition|(
name|i
operator|>=
name|DR_NADDR
condition|)
return|return
operator|-
literal|1
return|;
comment|/* Now set up the register I to watch our region.  */
comment|/* Record the info in our local mirrored array.  */
name|dr_mirror
index|[
name|i
index|]
operator|=
name|addr
expr_stmt|;
name|dr_ref_count
index|[
name|i
index|]
operator|=
literal|1
expr_stmt|;
name|I386_DR_SET_RW_LEN
argument_list|(
name|i
argument_list|,
name|len_rw_bits
argument_list|)
expr_stmt|;
comment|/* Note: we only enable the watchpoint locally, i.e. in the current      task.  Currently, no i386 target allows or supports global      watchpoints; however, if any target would want that in the      future, GDB should probably provide a command to control whether      to enable watchpoints globally or locally, and the code below      should use global or local enable and slow-down flags as      appropriate.  */
name|I386_DR_LOCAL_ENABLE
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|dr_control_mirror
operator||=
name|DR_LOCAL_SLOWDOWN
expr_stmt|;
name|dr_control_mirror
operator|&=
name|I386_DR_CONTROL_MASK
expr_stmt|;
comment|/* Finally, actually pass the info to the inferior.  */
name|I386_DR_LOW_SET_ADDR
argument_list|(
name|i
argument_list|,
name|addr
argument_list|)
expr_stmt|;
name|I386_DR_LOW_SET_CONTROL
argument_list|(
name|dr_control_mirror
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Remove a watchpoint at address ADDR, which is assumed to be aligned    according to the length of the region to watch.  LEN_RW_BITS is the    value of the bits from DR7 which describes the length and access    type of the region watched by this watchpoint.  Return 0 on    success, -1 on failure.  */
end_comment

begin_function
specifier|static
name|int
name|i386_remove_aligned_watchpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|unsigned
name|len_rw_bits
parameter_list|)
block|{
name|int
name|i
decl_stmt|,
name|retval
init|=
operator|-
literal|1
decl_stmt|;
name|ALL_DEBUG_REGISTERS
argument_list|(
argument|i
argument_list|)
block|{
if|if
condition|(
operator|!
name|I386_DR_VACANT
argument_list|(
name|i
argument_list|)
operator|&&
name|dr_mirror
index|[
name|i
index|]
operator|==
name|addr
operator|&&
name|I386_DR_GET_RW_LEN
argument_list|(
name|i
argument_list|)
operator|==
name|len_rw_bits
condition|)
block|{
if|if
condition|(
operator|--
name|dr_ref_count
index|[
name|i
index|]
operator|==
literal|0
condition|)
comment|/* no longer in use? */
block|{
comment|/* Reset our mirror.  */
name|dr_mirror
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|I386_DR_DISABLE
argument_list|(
name|i
argument_list|)
expr_stmt|;
comment|/* Reset it in the inferior.  */
name|I386_DR_LOW_SET_CONTROL
argument_list|(
name|dr_control_mirror
argument_list|)
expr_stmt|;
name|I386_DR_LOW_RESET_ADDR
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|retval
operator|=
literal|0
expr_stmt|;
block|}
block|}
return|return
name|retval
return|;
block|}
end_function

begin_comment
comment|/* Insert or remove a (possibly non-aligned) watchpoint, or count the    number of debug registers required to watch a region at address    ADDR whose length is LEN for accesses of type TYPE.  Return 0 on    successful insertion or removal, a positive number when queried    about the number of registers, or -1 on failure.  If WHAT is not a    valid value, bombs through internal_error.  */
end_comment

begin_function
specifier|static
name|int
name|i386_handle_nonaligned_watchpoint
parameter_list|(
name|i386_wp_op_t
name|what
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|,
name|int
name|len
parameter_list|,
name|enum
name|target_hw_bp_type
name|type
parameter_list|)
block|{
name|int
name|retval
init|=
literal|0
decl_stmt|,
name|status
init|=
literal|0
decl_stmt|;
name|int
name|max_wp_len
init|=
name|TARGET_HAS_DR_LEN_8
condition|?
literal|8
else|:
literal|4
decl_stmt|;
specifier|static
name|int
name|size_try_array
index|[
literal|8
index|]
index|[
literal|8
index|]
init|=
block|{
block|{
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|}
block|,
comment|/* Trying size one.  */
block|{
literal|2
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|}
block|,
comment|/* Trying size two.  */
block|{
literal|2
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|}
block|,
comment|/* Trying size three.  */
block|{
literal|4
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|,
literal|4
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|}
block|,
comment|/* Trying size four.  */
block|{
literal|4
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|,
literal|4
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|}
block|,
comment|/* Trying size five.  */
block|{
literal|4
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|,
literal|4
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|}
block|,
comment|/* Trying size six.  */
block|{
literal|4
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|,
literal|4
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|}
block|,
comment|/* Trying size seven.  */
block|{
literal|8
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|,
literal|4
block|,
literal|1
block|,
literal|2
block|,
literal|1
block|}
block|,
comment|/* Trying size eight.  */
block|}
decl_stmt|;
while|while
condition|(
name|len
operator|>
literal|0
condition|)
block|{
name|int
name|align
init|=
name|addr
operator|%
name|max_wp_len
decl_stmt|;
comment|/* Four (eigth on AMD64) is the maximum length a debug register 	 can watch.  */
name|int
name|try
init|=
operator|(
name|len
operator|>
name|max_wp_len
condition|?
operator|(
name|max_wp_len
operator|-
literal|1
operator|)
else|:
name|len
operator|-
literal|1
operator|)
decl_stmt|;
name|int
name|size
init|=
name|size_try_array
index|[
name|try
index|]
index|[
name|align
index|]
decl_stmt|;
if|if
condition|(
name|what
operator|==
name|WP_COUNT
condition|)
block|{
comment|/* size_try_array[] is defined such that each iteration 	     through the loop is guaranteed to produce an address and a 	     size that can be watched with a single debug register. 	     Thus, for counting the registers required to watch a 	     region, we simply need to increment the count on each 	     iteration.  */
name|retval
operator|++
expr_stmt|;
block|}
else|else
block|{
name|unsigned
name|len_rw
init|=
name|i386_length_and_rw_bits
argument_list|(
name|size
argument_list|,
name|type
argument_list|)
decl_stmt|;
if|if
condition|(
name|what
operator|==
name|WP_INSERT
condition|)
name|status
operator|=
name|i386_insert_aligned_watchpoint
argument_list|(
name|addr
argument_list|,
name|len_rw
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|what
operator|==
name|WP_REMOVE
condition|)
name|status
operator|=
name|i386_remove_aligned_watchpoint
argument_list|(
name|addr
argument_list|,
name|len_rw
argument_list|)
expr_stmt|;
else|else
name|internal_error
argument_list|(
name|__FILE__
argument_list|,
name|__LINE__
argument_list|,
literal|"\ Invalid value %d of operation in i386_handle_nonaligned_watchpoint.\n"
argument_list|,
operator|(
name|int
operator|)
name|what
argument_list|)
expr_stmt|;
comment|/* We keep the loop going even after a failure, because some 	     of the other aligned watchpoints might still succeed 	     (e.g. if they watch addresses that are already watched, 	     in which case we just increment the reference counts of 	     occupied debug registers).  If we break out of the loop 	     too early, we could cause those addresses watched by 	     other watchpoints to be disabled when breakpoint.c reacts 	     to our failure to insert this watchpoint and tries to 	     remove it.  */
if|if
condition|(
name|status
condition|)
name|retval
operator|=
name|status
expr_stmt|;
block|}
name|addr
operator|+=
name|size
expr_stmt|;
name|len
operator|-=
name|size
expr_stmt|;
block|}
return|return
name|retval
return|;
block|}
end_function

begin_comment
comment|/* Insert a watchpoint to watch a memory region which starts at    address ADDR and whose length is LEN bytes.  Watch memory accesses    of the type TYPE.  Return 0 on success, -1 on failure.  */
end_comment

begin_function
name|int
name|i386_insert_watchpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|type
parameter_list|)
block|{
name|int
name|retval
decl_stmt|;
if|if
condition|(
operator|(
operator|(
name|len
operator|!=
literal|1
operator|&&
name|len
operator|!=
literal|2
operator|&&
name|len
operator|!=
literal|4
operator|)
operator|&&
operator|!
operator|(
name|TARGET_HAS_DR_LEN_8
operator|&&
name|len
operator|==
literal|8
operator|)
operator|)
operator|||
name|addr
operator|%
name|len
operator|!=
literal|0
condition|)
name|retval
operator|=
name|i386_handle_nonaligned_watchpoint
argument_list|(
name|WP_INSERT
argument_list|,
name|addr
argument_list|,
name|len
argument_list|,
name|type
argument_list|)
expr_stmt|;
else|else
block|{
name|unsigned
name|len_rw
init|=
name|i386_length_and_rw_bits
argument_list|(
name|len
argument_list|,
name|type
argument_list|)
decl_stmt|;
name|retval
operator|=
name|i386_insert_aligned_watchpoint
argument_list|(
name|addr
argument_list|,
name|len_rw
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|maint_show_dr
condition|)
name|i386_show_dr
argument_list|(
literal|"insert_watchpoint"
argument_list|,
name|addr
argument_list|,
name|len
argument_list|,
name|type
argument_list|)
expr_stmt|;
return|return
name|retval
return|;
block|}
end_function

begin_comment
comment|/* Remove a watchpoint that watched the memory region which starts at    address ADDR, whose length is LEN bytes, and for accesses of the    type TYPE.  Return 0 on success, -1 on failure.  */
end_comment

begin_function
name|int
name|i386_remove_watchpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|type
parameter_list|)
block|{
name|int
name|retval
decl_stmt|;
if|if
condition|(
operator|(
operator|(
name|len
operator|!=
literal|1
operator|&&
name|len
operator|!=
literal|2
operator|&&
name|len
operator|!=
literal|4
operator|)
operator|&&
operator|!
operator|(
name|TARGET_HAS_DR_LEN_8
operator|&&
name|len
operator|==
literal|8
operator|)
operator|)
operator|||
name|addr
operator|%
name|len
operator|!=
literal|0
condition|)
name|retval
operator|=
name|i386_handle_nonaligned_watchpoint
argument_list|(
name|WP_REMOVE
argument_list|,
name|addr
argument_list|,
name|len
argument_list|,
name|type
argument_list|)
expr_stmt|;
else|else
block|{
name|unsigned
name|len_rw
init|=
name|i386_length_and_rw_bits
argument_list|(
name|len
argument_list|,
name|type
argument_list|)
decl_stmt|;
name|retval
operator|=
name|i386_remove_aligned_watchpoint
argument_list|(
name|addr
argument_list|,
name|len_rw
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|maint_show_dr
condition|)
name|i386_show_dr
argument_list|(
literal|"remove_watchpoint"
argument_list|,
name|addr
argument_list|,
name|len
argument_list|,
name|type
argument_list|)
expr_stmt|;
return|return
name|retval
return|;
block|}
end_function

begin_comment
comment|/* Return non-zero if we can watch a memory region that starts at    address ADDR and whose length is LEN bytes.  */
end_comment

begin_function
name|int
name|i386_region_ok_for_watchpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|int
name|len
parameter_list|)
block|{
name|int
name|nregs
decl_stmt|;
comment|/* Compute how many aligned watchpoints we would need to cover this      region.  */
name|nregs
operator|=
name|i386_handle_nonaligned_watchpoint
argument_list|(
name|WP_COUNT
argument_list|,
name|addr
argument_list|,
name|len
argument_list|,
name|hw_write
argument_list|)
expr_stmt|;
return|return
name|nregs
operator|<=
name|DR_NADDR
condition|?
literal|1
else|:
literal|0
return|;
block|}
end_function

begin_comment
comment|/* If the inferior has some watchpoint that triggered, return the    address associated with that watchpoint.  Otherwise, return zero.  */
end_comment

begin_function
name|CORE_ADDR
name|i386_stopped_data_address
parameter_list|(
name|void
parameter_list|)
block|{
name|CORE_ADDR
name|addr
init|=
literal|0
decl_stmt|;
name|int
name|i
decl_stmt|;
name|dr_status_mirror
operator|=
name|I386_DR_LOW_GET_STATUS
argument_list|()
expr_stmt|;
name|ALL_DEBUG_REGISTERS
argument_list|(
argument|i
argument_list|)
block|{
if|if
condition|(
name|I386_DR_WATCH_HIT
argument_list|(
name|i
argument_list|)
comment|/* This second condition makes sure DRi is set up for a data 	     watchpoint, not a hardware breakpoint.  The reason is 	     that GDB doesn't call the target_stopped_data_address 	     method except for data watchpoints.  In other words, I'm 	     being paranoid.  */
operator|&&
name|I386_DR_GET_RW_LEN
argument_list|(
name|i
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|addr
operator|=
name|dr_mirror
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|maint_show_dr
condition|)
name|i386_show_dr
argument_list|(
literal|"watchpoint_hit"
argument_list|,
name|addr
argument_list|,
operator|-
literal|1
argument_list|,
name|hw_write
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|maint_show_dr
operator|&&
name|addr
operator|==
literal|0
condition|)
name|i386_show_dr
argument_list|(
literal|"stopped_data_addr"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|hw_write
argument_list|)
expr_stmt|;
return|return
name|addr
return|;
block|}
end_function

begin_comment
comment|/* Return non-zero if the inferior has some break/watchpoint that    triggered.  */
end_comment

begin_function
name|int
name|i386_stopped_by_hwbp
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|dr_status_mirror
operator|=
name|I386_DR_LOW_GET_STATUS
argument_list|()
expr_stmt|;
if|if
condition|(
name|maint_show_dr
condition|)
name|i386_show_dr
argument_list|(
literal|"stopped_by_hwbp"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|hw_execute
argument_list|)
expr_stmt|;
name|ALL_DEBUG_REGISTERS
argument_list|(
argument|i
argument_list|)
block|{
if|if
condition|(
name|I386_DR_WATCH_HIT
argument_list|(
name|i
argument_list|)
condition|)
return|return
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Insert a hardware-assisted breakpoint at address ADDR.  SHADOW is    unused.  Return 0 on success, EBUSY on failure.  */
end_comment

begin_function
name|int
name|i386_insert_hw_breakpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|void
modifier|*
name|shadow
parameter_list|)
block|{
name|unsigned
name|len_rw
init|=
name|i386_length_and_rw_bits
argument_list|(
literal|1
argument_list|,
name|hw_execute
argument_list|)
decl_stmt|;
name|int
name|retval
init|=
name|i386_insert_aligned_watchpoint
argument_list|(
name|addr
argument_list|,
name|len_rw
argument_list|)
condition|?
name|EBUSY
else|:
literal|0
decl_stmt|;
if|if
condition|(
name|maint_show_dr
condition|)
name|i386_show_dr
argument_list|(
literal|"insert_hwbp"
argument_list|,
name|addr
argument_list|,
literal|1
argument_list|,
name|hw_execute
argument_list|)
expr_stmt|;
return|return
name|retval
return|;
block|}
end_function

begin_comment
comment|/* Remove a hardware-assisted breakpoint at address ADDR.  SHADOW is    unused.  Return 0 on success, -1 on failure.  */
end_comment

begin_function
name|int
name|i386_remove_hw_breakpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|void
modifier|*
name|shadow
parameter_list|)
block|{
name|unsigned
name|len_rw
init|=
name|i386_length_and_rw_bits
argument_list|(
literal|1
argument_list|,
name|hw_execute
argument_list|)
decl_stmt|;
name|int
name|retval
init|=
name|i386_remove_aligned_watchpoint
argument_list|(
name|addr
argument_list|,
name|len_rw
argument_list|)
decl_stmt|;
if|if
condition|(
name|maint_show_dr
condition|)
name|i386_show_dr
argument_list|(
literal|"remove_hwbp"
argument_list|,
name|addr
argument_list|,
literal|1
argument_list|,
name|hw_execute
argument_list|)
expr_stmt|;
return|return
name|retval
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I386_USE_GENERIC_WATCHPOINTS */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Provide a prototype to silence -Wmissing-prototypes.  */
end_comment

begin_function_decl
name|void
name|_initialize_i386_nat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_initialize_i386_nat
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|I386_USE_GENERIC_WATCHPOINTS
comment|/* A maintenance command to enable printing the internal DRi mirror      variables.  */
name|add_set_cmd
argument_list|(
literal|"show-debug-regs"
argument_list|,
name|class_maintenance
argument_list|,
name|var_boolean
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|maint_show_dr
argument_list|,
literal|"\ Set whether to show variables that mirror the x86 debug registers.\n\ Use \"on\" to enable, \"off\" to disable.\n\ If enabled, the debug registers values are shown when GDB inserts\n\ or removes a hardware breakpoint or watchpoint, and when the inferior\n\ triggers a breakpoint or watchpoint."
argument_list|,
operator|&
name|maintenancelist
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

