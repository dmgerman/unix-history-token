begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* OBSOLETE /* Remote debugging interface for AMD 29k interfaced via UDI, for GDB. */
end_comment

begin_comment
comment|/* OBSOLETE    Copyright 1990, 1992, 1993, 1994, 1995, 1996, 1998, 1999, 2000, 2001 */
end_comment

begin_comment
comment|/* OBSOLETE    Free Software Foundation, Inc. */
end_comment

begin_comment
comment|/* OBSOLETE    Written by Daniel Mann.  Contributed by AMD. */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE    This file is part of GDB. */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE    This program is free software; you can redistribute it and/or modify */
end_comment

begin_comment
comment|/* OBSOLETE    it under the terms of the GNU General Public License as published by */
end_comment

begin_comment
comment|/* OBSOLETE    the Free Software Foundation; either version 2 of the License, or */
end_comment

begin_comment
comment|/* OBSOLETE    (at your option) any later version. */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE    This program is distributed in the hope that it will be useful, */
end_comment

begin_comment
comment|/* OBSOLETE    but WITHOUT ANY WARRANTY; without even the implied warranty of */
end_comment

begin_comment
comment|/* OBSOLETE    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
end_comment

begin_comment
comment|/* OBSOLETE    GNU General Public License for more details. */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE    You should have received a copy of the GNU General Public License */
end_comment

begin_comment
comment|/* OBSOLETE    along with this program; if not, write to the Free Software */
end_comment

begin_comment
comment|/* OBSOLETE    Foundation, Inc., 59 Temple Place - Suite 330, */
end_comment

begin_comment
comment|/* OBSOLETE    Boston, MA 02111-1307, USA.  */
end_comment

begin_expr_stmt
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* This is like remote.c but uses the Universal Debug Interface (UDI) to  */
comment|/* OBSOLETE    talk to the target hardware (or simulator).  UDI is a TCP/IP based */
comment|/* OBSOLETE    protocol; for hardware that doesn't run TCP, an interface adapter  */
comment|/* OBSOLETE    daemon talks UDI on one side, and talks to the hardware (typically */
comment|/* OBSOLETE    over a serial port) on the other side. */
comment|/* OBSOLETE  */
comment|/* OBSOLETE    - Originally written by Daniel Mann at AMD for MiniMON and gdb 3.91.6. */
comment|/* OBSOLETE    - David Wood (wood@lab.ultra.nyu.edu) at New York University adapted this */
comment|/* OBSOLETE    file to gdb 3.95.  I was unable to get this working on sun3os4 */
comment|/* OBSOLETE    with termio, only with sgtty. */
comment|/* OBSOLETE    - Daniel Mann at AMD took the 3.95 adaptions above and replaced */
comment|/* OBSOLETE    MiniMON interface with UDI-p interface.        */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE #include "defs.h" */
comment|/* OBSOLETE #include "frame.h" */
comment|/* OBSOLETE #include "inferior.h" */
comment|/* OBSOLETE #include "value.h" */
comment|/* OBSOLETE #include<ctype.h> */
comment|/* OBSOLETE #include<fcntl.h> */
comment|/* OBSOLETE #include<errno.h> */
comment|/* OBSOLETE #include "gdb_string.h" */
comment|/* OBSOLETE #include "terminal.h" */
comment|/* OBSOLETE #include "target.h" */
comment|/* OBSOLETE #include "29k-share/udi/udiproc.h" */
comment|/* OBSOLETE #include "gdbcmd.h" */
comment|/* OBSOLETE #include "bfd.h" */
comment|/* OBSOLETE #include "gdbcore.h"		/* For download function */
operator|*
operator|/
comment|/* OBSOLETE #include "regcache.h" */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* access the register store directly, without going through */
comment|/* OBSOLETE    the normal handler functions. This avoids an extra data copy.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE extern int stop_soon_quietly;	/* for wait_for_inferior */
operator|*
operator|/
comment|/* OBSOLETE extern struct value *call_function_by_hand (); */
comment|/* OBSOLETE static void udi_resume (ptid_t ptid, int step, enum target_signal sig); */
comment|/* OBSOLETE static void udi_fetch_registers (int regno); */
comment|/* OBSOLETE static void udi_load (char *args, int from_tty); */
comment|/* OBSOLETE static void fetch_register (int regno); */
comment|/* OBSOLETE static void udi_store_registers (int regno); */
comment|/* OBSOLETE static int store_register (int regno); */
comment|/* OBSOLETE static int regnum_to_srnum (int regno); */
comment|/* OBSOLETE static void udi_close (int quitting); */
comment|/* OBSOLETE static CPUSpace udi_memory_space (CORE_ADDR addr); */
comment|/* OBSOLETE static int udi_write_inferior_memory (CORE_ADDR memaddr, char *myaddr, */
comment|/* OBSOLETE 				      int len); */
comment|/* OBSOLETE static int udi_read_inferior_memory (CORE_ADDR memaddr, char *myaddr, */
comment|/* OBSOLETE 				     int len); */
comment|/* OBSOLETE static void download (char *load_arg_string, int from_tty); */
comment|/* OBSOLETE char CoffFileName[100] = ""; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #define FREEZE_MODE     (read_register(CPS_REGNUM)& 0x400) */
comment|/* OBSOLETE #define USE_SHADOW_PC	((processor_type == a29k_freeze_mode)&& FREEZE_MODE) */
comment|/* OBSOLETE  */
comment|/* OBSOLETE static int timeout = 5; */
comment|/* OBSOLETE extern struct target_ops udi_ops;	/* Forward declaration */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Special register enumeration. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /******************************************************************* UDI DATA*/
operator|*
operator|/
comment|/* OBSOLETE #define	MAXDATA		2*1024	/* max UDI[read/write] byte size */
operator|*
operator|/
comment|/* OBSOLETE /* Descriptor for I/O to remote machine.  Initialize it to -1 so that */
comment|/* OBSOLETE    udi_open knows that we don't have a file open when the program */
comment|/* OBSOLETE    starts.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE UDISessionId udi_session_id = -1; */
comment|/* OBSOLETE static char *udi_config_id; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE CPUOffset IMemStart = 0; */
comment|/* OBSOLETE CPUSizeT IMemSize = 0; */
comment|/* OBSOLETE CPUOffset DMemStart = 0; */
comment|/* OBSOLETE CPUSizeT DMemSize = 0; */
comment|/* OBSOLETE CPUOffset RMemStart = 0; */
comment|/* OBSOLETE CPUSizeT RMemSize = 0; */
comment|/* OBSOLETE UDIUInt32 CPUPRL; */
comment|/* OBSOLETE UDIUInt32 CoProcPRL; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE UDIMemoryRange address_ranges[2];	/* Text and data */
operator|*
operator|/
comment|/* OBSOLETE UDIResource entry = */
comment|/* OBSOLETE {0, 0};				/* Entry point */
operator|*
operator|/
comment|/* OBSOLETE CPUSizeT stack_sizes[2];	/* Regular and memory stacks */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE #define	SBUF_MAX	1024	/* maximum size of string handling buffer */
operator|*
operator|/
comment|/* OBSOLETE char sbuf[SBUF_MAX]; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE typedef struct bkpt_entry_str */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     UDIResource Addr; */
comment|/* OBSOLETE     UDIUInt32 PassCount; */
comment|/* OBSOLETE     UDIBreakType Type; */
comment|/* OBSOLETE     unsigned int BreakId; */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE bkpt_entry_t; */
comment|/* OBSOLETE #define		BKPT_TABLE_SIZE 40 */
comment|/* OBSOLETE static bkpt_entry_t bkpt_table[BKPT_TABLE_SIZE]; */
comment|/* OBSOLETE extern char dfe_errmsg[];	/* error string */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* malloc'd name of the program on the remote system.  */
operator|*
operator|/
comment|/* OBSOLETE static char *prog_name = NULL; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* This is called not only when we first attach, but also when the */
comment|/* OBSOLETE    user types "run" after having attached.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE udi_create_inferior (char *execfile, char *args, char **env) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   char *args1; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (execfile) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       if (prog_name != NULL) */
comment|/* OBSOLETE 	xfree (prog_name); */
comment|/* OBSOLETE       prog_name = savestring (execfile, strlen (execfile)); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (entry.Offset) */
comment|/* OBSOLETE     execfile = ""; */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     error ("No image loaded into target."); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (udi_session_id< 0) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       /* If the TIP is not open, open it.  */
operator|*
operator|/
comment|/* OBSOLETE       if (UDIConnect (udi_config_id,&udi_session_id)) */
comment|/* OBSOLETE 	error ("UDIConnect() failed: %s\n", dfe_errmsg); */
comment|/* OBSOLETE       /* We will need to download the program.  */
operator|*
operator|/
comment|/* OBSOLETE       entry.Offset = 0; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   inferior_ptid = pid_to_ptid (40000); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (!entry.Offset) */
comment|/* OBSOLETE     download (execfile, 0); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   args1 = alloca (strlen (execfile) + strlen (args) + 2); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (execfile[0] == '\0') */
comment|/* OBSOLETE  */
comment|/* OBSOLETE     /* It is empty.  We need to quote it somehow, or else the target */
comment|/* OBSOLETE        will think there is no argument being passed here.  According */
comment|/* OBSOLETE        to the UDI spec it is quoted "according to TIP OS rules" which */
comment|/* OBSOLETE        I guess means quoting it like the Unix shell should work */
comment|/* OBSOLETE        (sounds pretty bogus to me...).  In fact it doesn't work (with */
comment|/* OBSOLETE        isstip anyway), but passing in two quotes as the argument seems */
comment|/* OBSOLETE        like a reasonable enough behavior anyway (I guess).  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE     strcpy (args1, "''"); */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     strcpy (args1, execfile); */
comment|/* OBSOLETE   strcat (args1, " "); */
comment|/* OBSOLETE   strcat (args1, args); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   UDIInitializeProcess (address_ranges,		/* ProcessMemory[] */
operator|*
operator|/
comment|/* OBSOLETE 			(UDIInt) 2,	/* NumberOfRanges */
operator|*
operator|/
comment|/* OBSOLETE 			entry,	/* EntryPoint */
operator|*
operator|/
comment|/* OBSOLETE 			stack_sizes,	/* *StackSizes */
operator|*
operator|/
comment|/* OBSOLETE 			(UDIInt) 2,	/* NumberOfStacks */
operator|*
operator|/
comment|/* OBSOLETE 			args1);	/* ArgString */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   init_wait_for_inferior (); */
comment|/* OBSOLETE   clear_proceed_status (); */
comment|/* OBSOLETE   proceed (-1, TARGET_SIGNAL_DEFAULT, 0); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE udi_mourn (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE #if 0 */
comment|/* OBSOLETE   /* Requiring "target udi" each time you run is a major pain.  I suspect */
comment|/* OBSOLETE      this was just blindy copied from remote.c, in which "target" and */
comment|/* OBSOLETE      "run" are combined.  Having a udi target without an inferior seems */
comment|/* OBSOLETE      to work between "target udi" and "run", so why not now?  */
operator|*
operator|/
comment|/* OBSOLETE   pop_target ();		/* Pop back to no-child state */
operator|*
operator|/
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE   /* But if we're going to want to run it again, we better remove the */
comment|/* OBSOLETE      breakpoints...  */
operator|*
operator|/
comment|/* OBSOLETE   remove_breakpoints (); */
comment|/* OBSOLETE   generic_mourn_inferior (); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /******************************************************************** UDI_OPEN */
comment|/* OBSOLETE ** Open a connection to remote TIP. */
comment|/* OBSOLETE    NAME is the socket domain used for communication with the TIP, */
comment|/* OBSOLETE    then a space and the socket name or TIP-host name. */
comment|/* OBSOLETE    '<udi_udi_config_id>' for example. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* XXX - need cleanups for udiconnect for various failures!!! */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE udi_open (char *name, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   unsigned int prl; */
comment|/* OBSOLETE   char *p; */
comment|/* OBSOLETE   int cnt; */
comment|/* OBSOLETE   UDIMemoryRange KnownMemory[10]; */
comment|/* OBSOLETE   UDIUInt32 ChipVersions[10]; */
comment|/* OBSOLETE   UDIInt NumberOfRanges = 10; */
comment|/* OBSOLETE   UDIInt NumberOfChips = 10; */
comment|/* OBSOLETE   UDIPId PId; */
comment|/* OBSOLETE   UDIUInt32 TIPId, TargetId, DFEId, DFE, TIP, DFEIPCId, TIPIPCId; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   target_preopen (from_tty); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   entry.Offset = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (cnt = 0; cnt< BKPT_TABLE_SIZE; cnt++) */
comment|/* OBSOLETE     bkpt_table[cnt].Type = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (udi_config_id) */
comment|/* OBSOLETE     xfree (udi_config_id); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (!name) */
comment|/* OBSOLETE     error ("Usage: target udi config_id, where config_id appears in udi_soc file"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   udi_config_id = xstrdup (strtok (name, " \t")); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (UDIConnect (udi_config_id,&udi_session_id)) */
comment|/* OBSOLETE     /* FIXME: Should set udi_session_id to -1 here.  */
operator|*
operator|/
comment|/* OBSOLETE     error ("UDIConnect() failed: %s\n", dfe_errmsg); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   push_target (&udi_ops); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* */
comment|/* OBSOLETE      ** Initialize target configuration structure (global) */
comment|/* OBSOLETE    */
operator|*
operator|/
comment|/* OBSOLETE   if (UDIGetTargetConfig (KnownMemory,&NumberOfRanges, */
comment|/* OBSOLETE 			  ChipVersions,&NumberOfChips)) */
comment|/* OBSOLETE     error ("UDIGetTargetConfig() failed"); */
comment|/* OBSOLETE   if (NumberOfChips> 2) */
comment|/* OBSOLETE     fprintf_unfiltered (gdb_stderr, "Target has more than one processor\n"); */
comment|/* OBSOLETE   for (cnt = 0; cnt< NumberOfRanges; cnt++) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       switch (KnownMemory[cnt].Space) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	default: */
comment|/* OBSOLETE 	  fprintf_unfiltered (gdb_stderr, "UDIGetTargetConfig() unknown memory space\n"); */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case UDI29KCP_S: */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case UDI29KIROMSpace: */
comment|/* OBSOLETE 	  RMemStart = KnownMemory[cnt].Offset; */
comment|/* OBSOLETE 	  RMemSize = KnownMemory[cnt].Size; */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case UDI29KIRAMSpace: */
comment|/* OBSOLETE 	  IMemStart = KnownMemory[cnt].Offset; */
comment|/* OBSOLETE 	  IMemSize = KnownMemory[cnt].Size; */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case UDI29KDRAMSpace: */
comment|/* OBSOLETE 	  DMemStart = KnownMemory[cnt].Offset; */
comment|/* OBSOLETE 	  DMemSize = KnownMemory[cnt].Size; */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   a29k_get_processor_type (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (UDICreateProcess (&PId)) */
comment|/* OBSOLETE     fprintf_unfiltered (gdb_stderr, "UDICreateProcess() failed\n"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Print out some stuff, letting the user now what's going on */
operator|*
operator|/
comment|/* OBSOLETE   if (UDICapabilities (&TIPId,&TargetId, DFEId, DFE,&TIP,&DFEIPCId, */
comment|/* OBSOLETE&TIPIPCId, sbuf)) */
comment|/* OBSOLETE     error ("UDICapabilities() failed"); */
comment|/* OBSOLETE   if (from_tty) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf_filtered ("Connected via UDI socket,\n\ */
comment|/* OBSOLETE  DFE-IPC version %x.%x.%x  TIP-IPC version %x.%x.%x  TIP version %x.%x.%x\n %s\n", */
comment|/* OBSOLETE 	       (DFEIPCId>> 8)& 0xf, (DFEIPCId>> 4)& 0xf, DFEIPCId& 0xf, */
comment|/* OBSOLETE 	       (TIPIPCId>> 8)& 0xf, (TIPIPCId>> 4)& 0xf, TIPIPCId& 0xf, */
comment|/* OBSOLETE 	       (TargetId>> 8)& 0xf, (TargetId>> 4)& 0xf, TargetId& 0xf, */
comment|/* OBSOLETE 		       sbuf); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /******************************************************************* UDI_CLOSE */
comment|/* OBSOLETE    Close the open connection to the TIP process. */
comment|/* OBSOLETE    Use this when you want to detach and do something else */
comment|/* OBSOLETE    with your gdb.  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE udi_close (			/*FIXME: how is quitting used */
operator|*
operator|/
comment|/* OBSOLETE 	    int quitting) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   if (udi_session_id< 0) */
comment|/* OBSOLETE     return; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* We should never get here if there isn't something valid in */
comment|/* OBSOLETE      udi_session_id.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (UDIDisconnect (udi_session_id, UDITerminateSession)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       if (quitting) */
comment|/* OBSOLETE 	warning ("UDIDisconnect() failed in udi_close"); */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	error ("UDIDisconnect() failed in udi_close"); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Do not try to close udi_session_id again, later in the program.  */
operator|*
operator|/
comment|/* OBSOLETE   udi_session_id = -1; */
comment|/* OBSOLETE   inferior_ptid = null_ptid; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   printf_filtered ("  Ending remote debugging\n"); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /**************************************************************** UDI_ATACH */
operator|*
operator|/
comment|/* OBSOLETE /* Attach to a program that is already loaded and running  */
comment|/* OBSOLETE  * Upon exiting the process's execution is stopped. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE udi_attach (char *args, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   UDIResource From; */
comment|/* OBSOLETE   UDIInt32 PC_adds; */
comment|/* OBSOLETE   UDICount Count = 1; */
comment|/* OBSOLETE   UDISizeT Size = 4; */
comment|/* OBSOLETE   UDICount CountDone; */
comment|/* OBSOLETE   UDIBool HostEndian = 0; */
comment|/* OBSOLETE   UDIError err; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (args == NULL) */
comment|/* OBSOLETE     error_no_arg ("program to attach"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (udi_session_id< 0) */
comment|/* OBSOLETE     error ("UDI connection not opened yet, use the 'target udi' command.\n"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (from_tty) */
comment|/* OBSOLETE     printf_unfiltered ("Attaching to remote program %s...\n", prog_name); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   UDIStop (); */
comment|/* OBSOLETE   From.Space = UDI29KSpecialRegs; */
comment|/* OBSOLETE   From.Offset = 11; */
comment|/* OBSOLETE   if (err = UDIRead (From,&PC_adds, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIRead failed in udi_attach"); */
comment|/* OBSOLETE   printf_unfiltered ("Remote process is now halted, pc1 = 0x%x.\n", PC_adds); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /************************************************************* UDI_DETACH */
operator|*
operator|/
comment|/* OBSOLETE /* Terminate the open connection to the TIP process. */
comment|/* OBSOLETE    Use this when you want to detach and do something else */
comment|/* OBSOLETE    with your gdb.  Leave remote process running (with no breakpoints set). */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE udi_detach (char *args, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   remove_breakpoints ();	/* Just in case there were any left in */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (UDIDisconnect (udi_session_id, UDIContinueSession)) */
comment|/* OBSOLETE     error ("UDIDisconnect() failed in udi_detach"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Don't try to UDIDisconnect it again in udi_close, which is called from */
comment|/* OBSOLETE      pop_target.  */
operator|*
operator|/
comment|/* OBSOLETE   udi_session_id = -1; */
comment|/* OBSOLETE   inferior_ptid = null_ptid; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   pop_target (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (from_tty) */
comment|/* OBSOLETE     printf_unfiltered ("Detaching from TIP\n"); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /****************************************************************** UDI_RESUME */
comment|/* OBSOLETE ** Tell the remote machine to resume.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE udi_resume (ptid_t ptid, int step, enum target_signal sig) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   UDIError tip_error; */
comment|/* OBSOLETE   UDIUInt32 Steps = 1; */
comment|/* OBSOLETE   UDIStepType StepType = UDIStepNatural; */
comment|/* OBSOLETE   UDIRange Range; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (step)			/* step 1 instruction */
operator|*
operator|/
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       tip_error = UDIStep (Steps, StepType, Range); */
comment|/* OBSOLETE       if (!tip_error) */
comment|/* OBSOLETE 	return; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE       fprintf_unfiltered (gdb_stderr, "UDIStep() error = %d\n", tip_error); */
comment|/* OBSOLETE       error ("failed in udi_resume"); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (UDIExecute ()) */
comment|/* OBSOLETE     error ("UDIExecute() failed in udi_resume"); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /******************************************************************** UDI_WAIT */
comment|/* OBSOLETE ** Wait until the remote machine stops, then return, */
comment|/* OBSOLETE    storing status in STATUS just as `wait' would.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static ptid_t */
comment|/* OBSOLETE udi_wait (ptid_t ptid, struct target_waitstatus *status) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   UDIInt32 MaxTime; */
comment|/* OBSOLETE   UDIPId PId; */
comment|/* OBSOLETE   UDIInt32 StopReason; */
comment|/* OBSOLETE   UDISizeT CountDone; */
comment|/* OBSOLETE   int old_timeout = timeout; */
comment|/* OBSOLETE   int old_immediate_quit = immediate_quit; */
comment|/* OBSOLETE   int i; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   status->kind = TARGET_WAITKIND_EXITED; */
comment|/* OBSOLETE   status->value.integer = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* wait for message to arrive. It should be: */
comment|/* OBSOLETE    If the target stops executing, udi_wait() should return. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE   timeout = 0;			/* Wait indefinetly for a message */
operator|*
operator|/
comment|/* OBSOLETE   immediate_quit = 1;		/* Helps ability to QUIT */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   while (1) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       i = 0; */
comment|/* OBSOLETE       MaxTime = UDIWaitForever; */
comment|/* OBSOLETE       UDIWait (MaxTime,&PId,&StopReason); */
comment|/* OBSOLETE       QUIT;			/* Let user quit if they want */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE       switch (StopReason& UDIGrossState) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	case UDIStdoutReady: */
comment|/* OBSOLETE 	  if (UDIGetStdout (sbuf, (UDISizeT) SBUF_MAX,&CountDone)) */
comment|/* OBSOLETE 	    /* This is said to happen if the program tries to output */
comment|/* OBSOLETE 	       a whole bunch of output (more than SBUF_MAX, I would */
comment|/* OBSOLETE 	       guess).  It doesn't seem to happen with the simulator.  */
operator|*
operator|/
comment|/* OBSOLETE 	    warning ("UDIGetStdout() failed in udi_wait"); */
comment|/* OBSOLETE 	  fwrite (sbuf, 1, CountDone, stdout); */
comment|/* OBSOLETE 	  gdb_flush (gdb_stdout); */
comment|/* OBSOLETE 	  continue; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	case UDIStderrReady: */
comment|/* OBSOLETE 	  UDIGetStderr (sbuf, (UDISizeT) SBUF_MAX,&CountDone); */
comment|/* OBSOLETE 	  fwrite (sbuf, 1, CountDone, stderr); */
comment|/* OBSOLETE 	  gdb_flush (gdb_stderr); */
comment|/* OBSOLETE 	  continue; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	case UDIStdinNeeded: */
comment|/* OBSOLETE 	  { */
comment|/* OBSOLETE 	    int ch; */
comment|/* OBSOLETE 	    i = 0; */
comment|/* OBSOLETE 	    do */
comment|/* OBSOLETE 	      { */
comment|/* OBSOLETE 		ch = getchar (); */
comment|/* OBSOLETE 		if (ch == EOF) */
comment|/* OBSOLETE 		  break; */
comment|/* OBSOLETE 		sbuf[i++] = ch; */
comment|/* OBSOLETE 	      } */
comment|/* OBSOLETE 	    while (i< SBUF_MAX&& ch != '\n'); */
comment|/* OBSOLETE 	    UDIPutStdin (sbuf, (UDISizeT) i,&CountDone); */
comment|/* OBSOLETE 	    continue; */
comment|/* OBSOLETE 	  } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	case UDIRunning: */
comment|/* OBSOLETE 	  /* In spite of the fact that we told UDIWait to wait forever, it will */
comment|/* OBSOLETE 	     return spuriously sometimes.  */
operator|*
operator|/
comment|/* OBSOLETE 	case UDIStdinModeX: */
comment|/* OBSOLETE 	  continue; */
comment|/* OBSOLETE 	default: */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   switch (StopReason& UDIGrossState) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE     case UDITrapped: */
comment|/* OBSOLETE       printf_unfiltered ("Am290*0 received vector number %d\n", StopReason>> 24); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE       switch ((StopReason>> 8)& 0xff) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	case 0:		/* Illegal opcode */
operator|*
operator|/
comment|/* OBSOLETE 	  printf_unfiltered ("	(break point)\n"); */
comment|/* OBSOLETE 	  status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE 	  status->value.sig = TARGET_SIGNAL_TRAP; */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case 1:		/* Unaligned Access */
operator|*
operator|/
comment|/* OBSOLETE 	  status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE 	  status->value.sig = TARGET_SIGNAL_BUS; */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case 3: */
comment|/* OBSOLETE 	case 4: */
comment|/* OBSOLETE 	  status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE 	  status->value.sig = TARGET_SIGNAL_FPE; */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case 5:		/* Protection Violation */
operator|*
operator|/
comment|/* OBSOLETE 	  status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE 	  /* Why not SEGV?  What is a Protection Violation?  */
operator|*
operator|/
comment|/* OBSOLETE 	  status->value.sig = TARGET_SIGNAL_ILL; */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case 6: */
comment|/* OBSOLETE 	case 7: */
comment|/* OBSOLETE 	case 8:		/* User Instruction Mapping Miss */
operator|*
operator|/
comment|/* OBSOLETE 	case 9:		/* User Data Mapping Miss */
operator|*
operator|/
comment|/* OBSOLETE 	case 10:		/* Supervisor Instruction Mapping Miss */
operator|*
operator|/
comment|/* OBSOLETE 	case 11:		/* Supervisor Data Mapping Miss */
operator|*
operator|/
comment|/* OBSOLETE 	  status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE 	  status->value.sig = TARGET_SIGNAL_SEGV; */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case 12: */
comment|/* OBSOLETE 	case 13: */
comment|/* OBSOLETE 	  status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE 	  status->value.sig = TARGET_SIGNAL_ILL; */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case 14:		/* Timer */
operator|*
operator|/
comment|/* OBSOLETE 	  status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE 	  status->value.sig = TARGET_SIGNAL_ALRM; */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case 15:		/* Trace */
operator|*
operator|/
comment|/* OBSOLETE 	  status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE 	  status->value.sig = TARGET_SIGNAL_TRAP; */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case 16:		/* INTR0 */
operator|*
operator|/
comment|/* OBSOLETE 	case 17:		/* INTR1 */
operator|*
operator|/
comment|/* OBSOLETE 	case 18:		/* INTR2 */
operator|*
operator|/
comment|/* OBSOLETE 	case 19:		/* INTR3/Internal */
operator|*
operator|/
comment|/* OBSOLETE 	case 20:		/* TRAP0 */
operator|*
operator|/
comment|/* OBSOLETE 	case 21:		/* TRAP1 */
operator|*
operator|/
comment|/* OBSOLETE 	  status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE 	  status->value.sig = TARGET_SIGNAL_INT; */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case 22:		/* Floating-Point Exception */
operator|*
operator|/
comment|/* OBSOLETE 	  status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE 	  /* Why not FPE?  */
operator|*
operator|/
comment|/* OBSOLETE 	  status->value.sig = TARGET_SIGNAL_ILL; */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case 77:		/* assert 77 */
operator|*
operator|/
comment|/* OBSOLETE 	  status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE 	  status->value.sig = TARGET_SIGNAL_TRAP; */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	default: */
comment|/* OBSOLETE 	  status->kind = TARGET_WAITKIND_EXITED; */
comment|/* OBSOLETE 	  status->value.integer = 0; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     case UDINotExecuting: */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_TERM; */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     case UDIStopped: */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_TSTP; */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     case UDIWarned: */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_URG; */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     case UDIStepped: */
comment|/* OBSOLETE     case UDIBreak: */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_TRAP; */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     case UDIWaiting: */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_STOP; */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     case UDIHalted: */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_KILL; */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     case UDIExited: */
comment|/* OBSOLETE     default: */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_EXITED; */
comment|/* OBSOLETE       status->value.integer = 0; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   timeout = old_timeout;	/* Restore original timeout value */
operator|*
operator|/
comment|/* OBSOLETE   immediate_quit = old_immediate_quit; */
comment|/* OBSOLETE   return inferior_ptid; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if 0 */
comment|/* OBSOLETE /* Handy for debugging */
operator|*
operator|/
comment|/* OBSOLETE udi_pc (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   UDIResource From; */
comment|/* OBSOLETE   UDIUInt32 *To; */
comment|/* OBSOLETE   UDICount Count; */
comment|/* OBSOLETE   UDISizeT Size = 4; */
comment|/* OBSOLETE   UDICount CountDone; */
comment|/* OBSOLETE   UDIBool HostEndian = 0; */
comment|/* OBSOLETE   UDIError err; */
comment|/* OBSOLETE   int pc[2]; */
comment|/* OBSOLETE   unsigned long myregs[256]; */
comment|/* OBSOLETE   int i; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From.Space = UDI29KPC; */
comment|/* OBSOLETE   From.Offset = 0; */
comment|/* OBSOLETE   To = (UDIUInt32 *) pc; */
comment|/* OBSOLETE   Count = 2; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   err = UDIRead (From, To, Count, Size,&CountDone, HostEndian); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   printf_unfiltered ("err = %d, CountDone = %d, pc[0] = 0x%x, pc[1] = 0x%x\n", */
comment|/* OBSOLETE 		     err, CountDone, pc[0], pc[1]); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   udi_fetch_registers (-1); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   printf_unfiltered ("other pc1 = 0x%x, pc0 = 0x%x\n", *(int *)&registers[4 * PC_REGNUM], */
comment|/* OBSOLETE 		     *(int *)&registers[4 * NPC_REGNUM]); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Now, read all the registers globally */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From.Space = UDI29KGlobalRegs; */
comment|/* OBSOLETE   From.Offset = 0; */
comment|/* OBSOLETE   err = UDIRead (From, myregs, 256, 4,&CountDone, HostEndian); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   printf ("err = %d, CountDone = %d\n", err, CountDone); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   printf ("\n"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (i = 0; i< 256; i += 2) */
comment|/* OBSOLETE     printf ("%d:\t%#10x\t%11d\t%#10x\t%11d\n", i, myregs[i], myregs[i], */
comment|/* OBSOLETE 	    myregs[i + 1], myregs[i + 1]); */
comment|/* OBSOLETE   printf ("\n"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   return pc[0]; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /********************************************************** UDI_FETCH_REGISTERS */
comment|/* OBSOLETE  * Read a remote register 'regno'.  */
comment|/* OBSOLETE  * If regno==-1 then read all the registers. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE udi_fetch_registers (int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   UDIResource From; */
comment|/* OBSOLETE   UDIUInt32 *To; */
comment|/* OBSOLETE   UDICount Count; */
comment|/* OBSOLETE   UDISizeT Size = 4; */
comment|/* OBSOLETE   UDICount CountDone; */
comment|/* OBSOLETE   UDIBool HostEndian = 0; */
comment|/* OBSOLETE   UDIError err; */
comment|/* OBSOLETE   int i; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (regno>= 0) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       fetch_register (regno); */
comment|/* OBSOLETE       return; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Gr1/rsp */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From.Space = UDI29KGlobalRegs; */
comment|/* OBSOLETE   From.Offset = 1; */
comment|/* OBSOLETE   To = (UDIUInt32 *)& registers[4 * GR1_REGNUM]; */
comment|/* OBSOLETE   Count = 1; */
comment|/* OBSOLETE   if (err = UDIRead (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIRead() failed in udi_fetch_registers"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   register_valid[GR1_REGNUM] = 1; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if defined(GR64_REGNUM)	/* Read gr64-127 */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Global Registers gr64-gr95 */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From.Space = UDI29KGlobalRegs; */
comment|/* OBSOLETE   From.Offset = 64; */
comment|/* OBSOLETE   To = (UDIUInt32 *)& registers[4 * GR64_REGNUM]; */
comment|/* OBSOLETE   Count = 32; */
comment|/* OBSOLETE   if (err = UDIRead (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIRead() failed in udi_fetch_registers"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (i = GR64_REGNUM; i< GR64_REGNUM + 32; i++) */
comment|/* OBSOLETE     register_valid[i] = 1; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #endif /*  GR64_REGNUM */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Global Registers gr96-gr127 */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From.Space = UDI29KGlobalRegs; */
comment|/* OBSOLETE   From.Offset = 96; */
comment|/* OBSOLETE   To = (UDIUInt32 *)& registers[4 * GR96_REGNUM]; */
comment|/* OBSOLETE   Count = 32; */
comment|/* OBSOLETE   if (err = UDIRead (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIRead() failed in udi_fetch_registers"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (i = GR96_REGNUM; i< GR96_REGNUM + 32; i++) */
comment|/* OBSOLETE     register_valid[i] = 1; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Local Registers */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From.Space = UDI29KLocalRegs; */
comment|/* OBSOLETE   From.Offset = 0; */
comment|/* OBSOLETE   To = (UDIUInt32 *)& registers[4 * LR0_REGNUM]; */
comment|/* OBSOLETE   Count = 128; */
comment|/* OBSOLETE   if (err = UDIRead (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIRead() failed in udi_fetch_registers"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (i = LR0_REGNUM; i< LR0_REGNUM + 128; i++) */
comment|/* OBSOLETE     register_valid[i] = 1; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Protected Special Registers */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From.Space = UDI29KSpecialRegs; */
comment|/* OBSOLETE   From.Offset = 0; */
comment|/* OBSOLETE   To = (UDIUInt32 *)& registers[4 * SR_REGNUM (0)]; */
comment|/* OBSOLETE   Count = 15; */
comment|/* OBSOLETE   if (err = UDIRead (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIRead() failed in udi_fetch_registers"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (i = SR_REGNUM (0); i< SR_REGNUM (0) + 15; i++) */
comment|/* OBSOLETE     register_valid[i] = 1; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (USE_SHADOW_PC) */
comment|/* OBSOLETE     {				/* Let regno_to_srnum() handle the register number */
operator|*
operator|/
comment|/* OBSOLETE       fetch_register (NPC_REGNUM); */
comment|/* OBSOLETE       fetch_register (PC_REGNUM); */
comment|/* OBSOLETE       fetch_register (PC2_REGNUM); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Unprotected Special Registers sr128-sr135 */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE       From.Space = UDI29KSpecialRegs; */
comment|/* OBSOLETE       From.Offset = 128; */
comment|/* OBSOLETE       To = (UDIUInt32 *)& registers[4 * SR_REGNUM (128)]; */
comment|/* OBSOLETE       Count = 135 - 128 + 1; */
comment|/* OBSOLETE       if (err = UDIRead (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE 	error ("UDIRead() failed in udi_fetch_registers"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE       for (i = SR_REGNUM (128); i< SR_REGNUM (128) + 135 - 128 + 1; i++) */
comment|/* OBSOLETE 	register_valid[i] = 1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (remote_debug) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       fprintf_unfiltered (gdb_stdlog, "Fetching all registers\n"); */
comment|/* OBSOLETE       fprintf_unfiltered (gdb_stdlog, */
comment|/* OBSOLETE 			  "Fetching PC0 = 0x%x, PC1 = 0x%x, PC2 = 0x%x\n", */
comment|/* OBSOLETE 			  read_register (NPC_REGNUM), */
comment|/* OBSOLETE 			  read_register (PC_REGNUM), */
comment|/* OBSOLETE 			  read_register (PC2_REGNUM)); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* There doesn't seem to be any way to get these.  */
operator|*
operator|/
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     int val = -1; */
comment|/* OBSOLETE     supply_register (FPE_REGNUM, (char *)&val); */
comment|/* OBSOLETE     supply_register (INTE_REGNUM, (char *)&val); */
comment|/* OBSOLETE     supply_register (FPS_REGNUM, (char *)&val); */
comment|/* OBSOLETE     supply_register (EXO_REGNUM, (char *)&val); */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /********************************************************* UDI_STORE_REGISTERS */
comment|/* OBSOLETE ** Store register regno into the target.   */
comment|/* OBSOLETE  * If regno==-1 then store all the registers. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE udi_store_registers (int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   UDIUInt32 *From; */
comment|/* OBSOLETE   UDIResource To; */
comment|/* OBSOLETE   UDICount Count; */
comment|/* OBSOLETE   UDISizeT Size = 4; */
comment|/* OBSOLETE   UDICount CountDone; */
comment|/* OBSOLETE   UDIBool HostEndian = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (regno>= 0) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       store_register (regno); */
comment|/* OBSOLETE       return; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (remote_debug) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       fprintf_unfiltered (gdb_stdlog, "Storing all registers\n"); */
comment|/* OBSOLETE       fprintf_unfiltered (gdb_stdlog, */
comment|/* OBSOLETE 			  "PC0 = 0x%x, PC1 = 0x%x, PC2 = 0x%x\n", */
comment|/* OBSOLETE 			  read_register (NPC_REGNUM), */
comment|/* OBSOLETE 			  read_register (PC_REGNUM), */
comment|/* OBSOLETE 			  read_register (PC2_REGNUM)); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Gr1/rsp */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From = (UDIUInt32 *)& registers[4 * GR1_REGNUM]; */
comment|/* OBSOLETE   To.Space = UDI29KGlobalRegs; */
comment|/* OBSOLETE   To.Offset = 1; */
comment|/* OBSOLETE   Count = 1; */
comment|/* OBSOLETE   if (UDIWrite (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIWrite() failed in udi_store_regisetrs"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if defined(GR64_REGNUM) */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Global registers gr64-gr95 */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From = (UDIUInt32 *)& registers[4 * GR64_REGNUM]; */
comment|/* OBSOLETE   To.Space = UDI29KGlobalRegs; */
comment|/* OBSOLETE   To.Offset = 64; */
comment|/* OBSOLETE   Count = 32; */
comment|/* OBSOLETE   if (UDIWrite (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIWrite() failed in udi_store_regisetrs"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #endif /* GR64_REGNUM */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Global registers gr96-gr127 */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From = (UDIUInt32 *)& registers[4 * GR96_REGNUM]; */
comment|/* OBSOLETE   To.Space = UDI29KGlobalRegs; */
comment|/* OBSOLETE   To.Offset = 96; */
comment|/* OBSOLETE   Count = 32; */
comment|/* OBSOLETE   if (UDIWrite (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIWrite() failed in udi_store_regisetrs"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Local Registers */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From = (UDIUInt32 *)& registers[4 * LR0_REGNUM]; */
comment|/* OBSOLETE   To.Space = UDI29KLocalRegs; */
comment|/* OBSOLETE   To.Offset = 0; */
comment|/* OBSOLETE   Count = 128; */
comment|/* OBSOLETE   if (UDIWrite (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIWrite() failed in udi_store_regisetrs"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Protected Special Registers */
comment|/* VAB through TMR */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From = (UDIUInt32 *)& registers[4 * SR_REGNUM (0)]; */
comment|/* OBSOLETE   To.Space = UDI29KSpecialRegs; */
comment|/* OBSOLETE   To.Offset = 0; */
comment|/* OBSOLETE   Count = 10; */
comment|/* OBSOLETE   if (UDIWrite (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIWrite() failed in udi_store_regisetrs"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* PC0, PC1, PC2 possibly as shadow registers */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From = (UDIUInt32 *)& registers[4 * SR_REGNUM (10)]; */
comment|/* OBSOLETE   To.Space = UDI29KSpecialRegs; */
comment|/* OBSOLETE   Count = 3; */
comment|/* OBSOLETE   if (USE_SHADOW_PC) */
comment|/* OBSOLETE     To.Offset = 20;		/* SPC0 */
operator|*
operator|/
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     To.Offset = 10;		/* PC0 */
operator|*
operator|/
comment|/* OBSOLETE   if (UDIWrite (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIWrite() failed in udi_store_regisetrs"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* PC1 via UDI29KPC */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From = (UDIUInt32 *)& registers[4 * PC_REGNUM]; */
comment|/* OBSOLETE   To.Space = UDI29KPC; */
comment|/* OBSOLETE   To.Offset = 0;		/* PC1 */
operator|*
operator|/
comment|/* OBSOLETE   Count = 1; */
comment|/* OBSOLETE   if (UDIWrite (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIWrite() failed in udi_store_regisetrs"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* LRU and MMU */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From = (UDIUInt32 *)& registers[4 * SR_REGNUM (13)]; */
comment|/* OBSOLETE   To.Space = UDI29KSpecialRegs; */
comment|/* OBSOLETE   To.Offset = 13; */
comment|/* OBSOLETE   Count = 2; */
comment|/* OBSOLETE   if (UDIWrite (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIWrite() failed in udi_store_regisetrs"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Unprotected Special Registers */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From = (UDIUInt32 *)& registers[4 * SR_REGNUM (128)]; */
comment|/* OBSOLETE   To.Space = UDI29KSpecialRegs; */
comment|/* OBSOLETE   To.Offset = 128; */
comment|/* OBSOLETE   Count = 135 - 128 + 1; */
comment|/* OBSOLETE   if (UDIWrite (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIWrite() failed in udi_store_regisetrs"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   registers_changed (); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /****************************************************** UDI_PREPARE_TO_STORE */
operator|*
operator|/
comment|/* OBSOLETE /* Get ready to modify the registers array.  On machines which store */
comment|/* OBSOLETE    individual registers, this doesn't need to do anything.  On machines */
comment|/* OBSOLETE    which store all the registers in one fell swoop, this makes sure */
comment|/* OBSOLETE    that registers contains all the registers from the program being */
comment|/* OBSOLETE    debugged.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE udi_prepare_to_store (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   /* Do nothing, since we can store individual regs */
operator|*
operator|/
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /********************************************************** TRANSLATE_ADDR */
operator|*
operator|/
comment|/* OBSOLETE static CORE_ADDR */
comment|/* OBSOLETE translate_addr (CORE_ADDR addr) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE #if defined(ULTRA3)&& defined(KERNEL_DEBUGGING) */
comment|/* OBSOLETE   /* Check for a virtual address in the kernel */
operator|*
operator|/
comment|/* OBSOLETE   /* Assume physical address of ublock is in  paddr_u register */
operator|*
operator|/
comment|/* OBSOLETE   /* FIXME: doesn't work for user virtual addresses */
operator|*
operator|/
comment|/* OBSOLETE   if (addr>= UVADDR) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       /* PADDR_U register holds the physical address of the ublock */
operator|*
operator|/
comment|/* OBSOLETE       CORE_ADDR i = (CORE_ADDR) read_register (PADDR_U_REGNUM); */
comment|/* OBSOLETE       return (i + addr - (CORE_ADDR) UVADDR); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       return (addr); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE   return (addr); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /************************************************* UDI_XFER_INFERIOR_MEMORY */
operator|*
operator|/
comment|/* OBSOLETE /* FIXME!  Merge these two.  */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE udi_xfer_inferior_memory (CORE_ADDR memaddr, char *myaddr, int len, int write, */
comment|/* OBSOLETE 			  struct mem_attrib *attrib ATTRIBUTE_UNUSED, */
comment|/* OBSOLETE 			  struct target_ops *target ATTRIBUTE_UNUSED) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   memaddr = translate_addr (memaddr); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (write) */
comment|/* OBSOLETE     return udi_write_inferior_memory (memaddr, myaddr, len); */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     return udi_read_inferior_memory (memaddr, myaddr, len); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /********************************************************** UDI_FILES_INFO */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE udi_files_info (struct target_ops *target) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   printf_unfiltered ("\tAttached to UDI socket to %s", udi_config_id); */
comment|/* OBSOLETE   if (prog_name != NULL) */
comment|/* OBSOLETE     printf_unfiltered ("and running program %s", prog_name); */
comment|/* OBSOLETE   printf_unfiltered (".\n"); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /**************************************************** UDI_INSERT_BREAKPOINT */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE udi_insert_breakpoint (CORE_ADDR addr, char *contents_cache) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int cnt; */
comment|/* OBSOLETE   UDIError err; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (cnt = 0; cnt< BKPT_TABLE_SIZE; cnt++) */
comment|/* OBSOLETE     if (bkpt_table[cnt].Type == 0)	/* Find first free slot */
operator|*
operator|/
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (cnt>= BKPT_TABLE_SIZE) */
comment|/* OBSOLETE     error ("Too many breakpoints set"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   bkpt_table[cnt].Addr.Offset = addr; */
comment|/* OBSOLETE   bkpt_table[cnt].Addr.Space = UDI29KIRAMSpace; */
comment|/* OBSOLETE   bkpt_table[cnt].PassCount = 1; */
comment|/* OBSOLETE   bkpt_table[cnt].Type = UDIBreakFlagExecute; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   err = UDISetBreakpoint (bkpt_table[cnt].Addr, */
comment|/* OBSOLETE 			  bkpt_table[cnt].PassCount, */
comment|/* OBSOLETE 			  bkpt_table[cnt].Type, */
comment|/* OBSOLETE&bkpt_table[cnt].BreakId); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (err == 0) */
comment|/* OBSOLETE     return 0;			/* Success */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   bkpt_table[cnt].Type = 0; */
comment|/* OBSOLETE   error ("UDISetBreakpoint returned error code %d\n", err); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /**************************************************** UDI_REMOVE_BREAKPOINT */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE udi_remove_breakpoint (CORE_ADDR addr, char *contents_cache) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int cnt; */
comment|/* OBSOLETE   UDIError err; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (cnt = 0; cnt< BKPT_TABLE_SIZE; cnt++) */
comment|/* OBSOLETE     if (bkpt_table[cnt].Addr.Offset == addr)	/* Find matching breakpoint */
operator|*
operator|/
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (cnt>= BKPT_TABLE_SIZE) */
comment|/* OBSOLETE     error ("Can't find breakpoint in table"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   bkpt_table[cnt].Type = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   err = UDIClearBreakpoint (bkpt_table[cnt].BreakId); */
comment|/* OBSOLETE   if (err == 0) */
comment|/* OBSOLETE     return 0;			/* Success */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   error ("UDIClearBreakpoint returned error code %d\n", err); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE udi_kill (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if 0 */
comment|/* OBSOLETE /* */
comment|/* OBSOLETE    UDIStop does not really work as advertised.  It causes the TIP to close it's */
comment|/* OBSOLETE    connection, which usually results in GDB dying with a SIGPIPE.  For now, we */
comment|/* OBSOLETE    just invoke udi_close, which seems to get things right. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE   UDIStop (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   udi_session_id = -1; */
comment|/* OBSOLETE   inferior_ptid = null_ptid; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (from_tty) */
comment|/* OBSOLETE     printf_unfiltered ("Target has been stopped."); */
comment|/* OBSOLETE #endif /* 0 */
operator|*
operator|/
comment|/* OBSOLETE #if 0 */
comment|/* OBSOLETE   udi_close (0); */
comment|/* OBSOLETE   pop_target (); */
comment|/* OBSOLETE #endif /* 0 */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Keep the target around, e.g. so "run" can do the right thing when */
comment|/* OBSOLETE      we are already debugging something.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (UDIDisconnect (udi_session_id, UDITerminateSession)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       warning ("UDIDisconnect() failed"); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Do not try to close udi_session_id again, later in the program.  */
operator|*
operator|/
comment|/* OBSOLETE   udi_session_id = -1; */
comment|/* OBSOLETE   inferior_ptid = null_ptid; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /*  */
comment|/* OBSOLETE    Load a program into the target.  Args are: `program {options}'.  The options */
comment|/* OBSOLETE    are used to control loading of the program, and are NOT passed onto the */
comment|/* OBSOLETE    loaded code as arguments.  (You need to use the `run' command to do that.) */
comment|/* OBSOLETE  */
comment|/* OBSOLETE    The options are: */
comment|/* OBSOLETE    -ms %d       Set mem stack size to %d */
comment|/* OBSOLETE    -rs %d       Set regular stack size to %d */
comment|/* OBSOLETE    -i   send init info (default) */
comment|/* OBSOLETE    -noi don't send init info */
comment|/* OBSOLETE    -[tT]        Load Text section */
comment|/* OBSOLETE    -[dD]        Load Data section */
comment|/* OBSOLETE    -[bB]        Load BSS section */
comment|/* OBSOLETE    -[lL]        Load Lit section */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE download (char *load_arg_string, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE #define DEFAULT_MEM_STACK_SIZE 		0x6000 */
comment|/* OBSOLETE #define DEFAULT_REG_STACK_SIZE 		0x2000 */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   char *token; */
comment|/* OBSOLETE   char *filename; */
comment|/* OBSOLETE   asection *section; */
comment|/* OBSOLETE   bfd *pbfd; */
comment|/* OBSOLETE   UDIError err; */
comment|/* OBSOLETE   int load_text = 1, load_data = 1, load_bss = 1, load_lit = 1; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   address_ranges[0].Space = UDI29KIRAMSpace; */
comment|/* OBSOLETE   address_ranges[0].Offset = 0xffffffff; */
comment|/* OBSOLETE   address_ranges[0].Size = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   address_ranges[1].Space = UDI29KDRAMSpace; */
comment|/* OBSOLETE   address_ranges[1].Offset = 0xffffffff; */
comment|/* OBSOLETE   address_ranges[1].Size = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   stack_sizes[0] = DEFAULT_REG_STACK_SIZE; */
comment|/* OBSOLETE   stack_sizes[1] = DEFAULT_MEM_STACK_SIZE; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   dont_repeat (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   filename = strtok (load_arg_string, " \t"); */
comment|/* OBSOLETE   if (!filename) */
comment|/* OBSOLETE     error ("Must specify at least a file name with the load command"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   filename = tilde_expand (filename); */
comment|/* OBSOLETE   make_cleanup (xfree, filename); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   while (token = strtok (NULL, " \t")) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       if (token[0] == '-') */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  token++; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	  if (STREQ (token, "ms")) */
comment|/* OBSOLETE 	    stack_sizes[1] = atol (strtok (NULL, " \t")); */
comment|/* OBSOLETE 	  else if (STREQ (token, "rs")) */
comment|/* OBSOLETE 	    stack_sizes[0] = atol (strtok (NULL, " \t")); */
comment|/* OBSOLETE 	  else */
comment|/* OBSOLETE 	    { */
comment|/* OBSOLETE 	      load_text = load_data = load_bss = load_lit = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	      while (*token) */
comment|/* OBSOLETE 		{ */
comment|/* OBSOLETE 		  switch (*token++) */
comment|/* OBSOLETE 		    { */
comment|/* OBSOLETE 		    case 't': */
comment|/* OBSOLETE 		    case 'T': */
comment|/* OBSOLETE 		      load_text = 1; */
comment|/* OBSOLETE 		      break; */
comment|/* OBSOLETE 		    case 'd': */
comment|/* OBSOLETE 		    case 'D': */
comment|/* OBSOLETE 		      load_data = 1; */
comment|/* OBSOLETE 		      break; */
comment|/* OBSOLETE 		    case 'b': */
comment|/* OBSOLETE 		    case 'B': */
comment|/* OBSOLETE 		      load_bss = 1; */
comment|/* OBSOLETE 		      break; */
comment|/* OBSOLETE 		    case 'l': */
comment|/* OBSOLETE 		    case 'L': */
comment|/* OBSOLETE 		      load_lit = 1; */
comment|/* OBSOLETE 		      break; */
comment|/* OBSOLETE 		    default: */
comment|/* OBSOLETE 		      error ("Unknown UDI load option -%s", token - 1); */
comment|/* OBSOLETE 		    } */
comment|/* OBSOLETE 		} */
comment|/* OBSOLETE 	    } */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   pbfd = bfd_openr (filename, gnutarget); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (!pbfd) */
comment|/* OBSOLETE     /* FIXME: should be using bfd_errmsg, not assuming it was */
comment|/* OBSOLETE        bfd_error_system_call.  */
operator|*
operator|/
comment|/* OBSOLETE     perror_with_name (filename); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* FIXME: should be checking for errors from bfd_close (for one thing, */
comment|/* OBSOLETE      on error it does not free all the storage associated with the */
comment|/* OBSOLETE      bfd).  */
operator|*
operator|/
comment|/* OBSOLETE   make_cleanup_bfd_close (pbfd); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   QUIT; */
comment|/* OBSOLETE   immediate_quit++; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (!bfd_check_format (pbfd, bfd_object)) */
comment|/* OBSOLETE     error ("It doesn't seem to be an object file"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (section = pbfd->sections; section; section = section->next) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       if (bfd_get_section_flags (pbfd, section)& SEC_ALLOC) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  UDIResource To; */
comment|/* OBSOLETE 	  UDICount Count; */
comment|/* OBSOLETE 	  unsigned long section_size, section_end; */
comment|/* OBSOLETE 	  const char *section_name; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	  section_name = bfd_get_section_name (pbfd, section); */
comment|/* OBSOLETE 	  if (STREQ (section_name, ".text")&& !load_text) */
comment|/* OBSOLETE 	    continue; */
comment|/* OBSOLETE 	  else if (STREQ (section_name, ".data")&& !load_data) */
comment|/* OBSOLETE 	    continue; */
comment|/* OBSOLETE 	  else if (STREQ (section_name, ".bss")&& !load_bss) */
comment|/* OBSOLETE 	    continue; */
comment|/* OBSOLETE 	  else if (STREQ (section_name, ".lit")&& !load_lit) */
comment|/* OBSOLETE 	    continue; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	  To.Offset = bfd_get_section_vma (pbfd, section); */
comment|/* OBSOLETE 	  section_size = bfd_section_size (pbfd, section); */
comment|/* OBSOLETE 	  section_end = To.Offset + section_size; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	  if (section_size == 0) */
comment|/* OBSOLETE 	    /* This is needed at least in the BSS case, where the code */
comment|/* OBSOLETE 	       below starts writing before it even checks the size.  */
operator|*
operator|/
comment|/* OBSOLETE 	    continue; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	  printf_unfiltered ("[Loading section %s at %x (%d bytes)]\n", */
comment|/* OBSOLETE 			     section_name, */
comment|/* OBSOLETE 			     To.Offset, */
comment|/* OBSOLETE 			     section_size); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	  if (bfd_get_section_flags (pbfd, section)& SEC_CODE) */
comment|/* OBSOLETE 	    { */
comment|/* OBSOLETE 	      To.Space = UDI29KIRAMSpace; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	      address_ranges[0].Offset = min (address_ranges[0].Offset, */
comment|/* OBSOLETE 					      To.Offset); */
comment|/* OBSOLETE 	      address_ranges[0].Size = max (address_ranges[0].Size, */
comment|/* OBSOLETE 					    section_end */
comment|/* OBSOLETE 					    - address_ranges[0].Offset); */
comment|/* OBSOLETE 	    } */
comment|/* OBSOLETE 	  else */
comment|/* OBSOLETE 	    { */
comment|/* OBSOLETE 	      To.Space = UDI29KDRAMSpace; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	      address_ranges[1].Offset = min (address_ranges[1].Offset, */
comment|/* OBSOLETE 					      To.Offset); */
comment|/* OBSOLETE 	      address_ranges[1].Size = max (address_ranges[1].Size, */
comment|/* OBSOLETE 					    section_end */
comment|/* OBSOLETE 					    - address_ranges[1].Offset); */
comment|/* OBSOLETE 	    } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	  if (bfd_get_section_flags (pbfd, section)& SEC_LOAD)		/* Text, data or lit */
operator|*
operator|/
comment|/* OBSOLETE 	    { */
comment|/* OBSOLETE 	      file_ptr fptr; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	      fptr = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	      while (section_size> 0) */
comment|/* OBSOLETE 		{ */
comment|/* OBSOLETE 		  char buffer[1024]; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 		  Count = min (section_size, 1024); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 		  bfd_get_section_contents (pbfd, section, buffer, fptr, */
comment|/* OBSOLETE 					    Count); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 		  err = UDIWrite ((UDIHostMemPtr) buffer,	/* From */
operator|*
operator|/
comment|/* OBSOLETE 				  To,	/* To */
operator|*
operator|/
comment|/* OBSOLETE 				  Count,	/* Count */
operator|*
operator|/
comment|/* OBSOLETE 				  (UDISizeT) 1,		/* Size */
operator|*
operator|/
comment|/* OBSOLETE&Count,	/* CountDone */
operator|*
operator|/
comment|/* OBSOLETE 				  (UDIBool) 0);		/* HostEndian */
operator|*
operator|/
comment|/* OBSOLETE 		  if (err) */
comment|/* OBSOLETE 		    error ("UDIWrite failed, error = %d", err); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 		  To.Offset += Count; */
comment|/* OBSOLETE 		  fptr += Count; */
comment|/* OBSOLETE 		  section_size -= Count; */
comment|/* OBSOLETE 		} */
comment|/* OBSOLETE 	    } */
comment|/* OBSOLETE 	  else */
comment|/* OBSOLETE 	    /* BSS */
operator|*
operator|/
comment|/* OBSOLETE 	    { */
comment|/* OBSOLETE 	      UDIResource From; */
comment|/* OBSOLETE 	      unsigned long zero = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	      /* Write a zero byte at the vma */
operator|*
operator|/
comment|/* OBSOLETE 	      /* FIXME: Broken for sections of 1-3 bytes (we test for */
comment|/* OBSOLETE 	         zero above).  */
operator|*
operator|/
comment|/* OBSOLETE 	      err = UDIWrite ((UDIHostMemPtr)& zero,	/* From */
operator|*
operator|/
comment|/* OBSOLETE 			      To,	/* To */
operator|*
operator|/
comment|/* OBSOLETE 			      (UDICount) 1,	/* Count */
operator|*
operator|/
comment|/* OBSOLETE 			      (UDISizeT) 4,	/* Size */
operator|*
operator|/
comment|/* OBSOLETE&Count,	/* CountDone */
operator|*
operator|/
comment|/* OBSOLETE 			      (UDIBool) 0);	/* HostEndian */
operator|*
operator|/
comment|/* OBSOLETE 	      if (err) */
comment|/* OBSOLETE 		error ("UDIWrite failed, error = %d", err); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	      From = To; */
comment|/* OBSOLETE 	      To.Offset += 4; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	      /* Now, duplicate it for the length of the BSS */
operator|*
operator|/
comment|/* OBSOLETE 	      err = UDICopy (From,	/* From */
operator|*
operator|/
comment|/* OBSOLETE 			     To,	/* To */
operator|*
operator|/
comment|/* OBSOLETE 			     (UDICount) (section_size / 4 - 1),		/* Count */
operator|*
operator|/
comment|/* OBSOLETE 			     (UDISizeT) 4,	/* Size */
operator|*
operator|/
comment|/* OBSOLETE&Count,	/* CountDone */
operator|*
operator|/
comment|/* OBSOLETE 			     (UDIBool) 1);	/* Direction */
operator|*
operator|/
comment|/* OBSOLETE 	      if (err) */
comment|/* OBSOLETE 		{ */
comment|/* OBSOLETE 		  char message[100]; */
comment|/* OBSOLETE 		  int xerr; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 		  xerr = UDIGetErrorMsg (err, 100, message,&Count); */
comment|/* OBSOLETE 		  if (!xerr) */
comment|/* OBSOLETE 		    fprintf_unfiltered (gdb_stderr, "Error is %s\n", message); */
comment|/* OBSOLETE 		  else */
comment|/* OBSOLETE 		    fprintf_unfiltered (gdb_stderr, "xerr is %d\n", xerr); */
comment|/* OBSOLETE 		  error ("UDICopy failed, error = %d", err); */
comment|/* OBSOLETE 		} */
comment|/* OBSOLETE 	    } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   entry.Space = UDI29KIRAMSpace; */
comment|/* OBSOLETE   entry.Offset = bfd_get_start_address (pbfd); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   immediate_quit--; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Function to download an image into the remote target.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE udi_load (char *args, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   download (args, from_tty); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* As a convenience, pick up any symbol info that is in the program */
comment|/* OBSOLETE      being loaded.  Note that we assume that the program is the``mainline''; */
comment|/* OBSOLETE      if this is not always true, then this code will need to be augmented.  */
operator|*
operator|/
comment|/* OBSOLETE   symbol_file_add (strtok (args, " \t"), from_tty, NULL, 1, 0); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Getting new symbols may change our opinion about what is */
comment|/* OBSOLETE      frameless.  */
operator|*
operator|/
comment|/* OBSOLETE   reinit_frame_cache (); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /*************************************************** UDI_WRITE_INFERIOR_MEMORY */
comment|/* OBSOLETE ** Copy LEN bytes of data from debugger memory at MYADDR */
comment|/* OBSOLETE    to inferior's memory at MEMADDR.  Returns number of bytes written.  */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE udi_write_inferior_memory (CORE_ADDR memaddr, char *myaddr, int len) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int nwritten = 0; */
comment|/* OBSOLETE   UDIUInt32 *From; */
comment|/* OBSOLETE   UDIResource To; */
comment|/* OBSOLETE   UDICount Count; */
comment|/* OBSOLETE   UDISizeT Size = 1; */
comment|/* OBSOLETE   UDICount CountDone = 0; */
comment|/* OBSOLETE   UDIBool HostEndian = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   To.Space = udi_memory_space (memaddr); */
comment|/* OBSOLETE   From = (UDIUInt32 *) myaddr; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   while (nwritten< len) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       Count = len - nwritten; */
comment|/* OBSOLETE       if (Count> MAXDATA) */
comment|/* OBSOLETE 	Count = MAXDATA; */
comment|/* OBSOLETE       To.Offset = memaddr + nwritten; */
comment|/* OBSOLETE       if (UDIWrite (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  error ("UDIWrite() failed in udi_write_inferior_memory"); */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  nwritten += CountDone; */
comment|/* OBSOLETE 	  From += CountDone; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   return (nwritten); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /**************************************************** UDI_READ_INFERIOR_MEMORY */
comment|/* OBSOLETE ** Read LEN bytes from inferior memory at MEMADDR.  Put the result */
comment|/* OBSOLETE    at debugger address MYADDR.  Returns number of bytes read.  */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE udi_read_inferior_memory (CORE_ADDR memaddr, char *myaddr, int len) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int nread = 0; */
comment|/* OBSOLETE   UDIResource From; */
comment|/* OBSOLETE   UDIUInt32 *To; */
comment|/* OBSOLETE   UDICount Count; */
comment|/* OBSOLETE   UDISizeT Size = 1; */
comment|/* OBSOLETE   UDICount CountDone = 0; */
comment|/* OBSOLETE   UDIBool HostEndian = 0; */
comment|/* OBSOLETE   UDIError err; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From.Space = udi_memory_space (memaddr); */
comment|/* OBSOLETE   To = (UDIUInt32 *) myaddr; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   while (nread< len) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       Count = len - nread; */
comment|/* OBSOLETE       if (Count> MAXDATA) */
comment|/* OBSOLETE 	Count = MAXDATA; */
comment|/* OBSOLETE       From.Offset = memaddr + nread; */
comment|/* OBSOLETE       if (err = UDIRead (From, To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  error ("UDIRead() failed in udi_read_inferior_memory"); */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  nread += CountDone; */
comment|/* OBSOLETE 	  To += CountDone; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   return (nread); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /********************************************************************* WARNING */
comment|/* OBSOLETE */
operator|*
operator|/
comment|/* OBSOLETE udi_warning (int num) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   error ("ERROR while loading program into remote TIP: $d\n", num); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /*****************************************************************************/
operator|*
operator|/
comment|/* OBSOLETE /* Fetch a single register indicatated by 'regno'.  */
comment|/* OBSOLETE  * Returns 0/-1 on success/failure.   */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE fetch_register (int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   UDIResource From; */
comment|/* OBSOLETE   UDIUInt32 To; */
comment|/* OBSOLETE   UDICount Count = 1; */
comment|/* OBSOLETE   UDISizeT Size = 4; */
comment|/* OBSOLETE   UDICount CountDone; */
comment|/* OBSOLETE   UDIBool HostEndian = 0; */
comment|/* OBSOLETE   UDIError err; */
comment|/* OBSOLETE   int result; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (regno == GR1_REGNUM) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       From.Space = UDI29KGlobalRegs; */
comment|/* OBSOLETE       From.Offset = 1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (regno>= GR96_REGNUM&& regno< GR96_REGNUM + 32) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       From.Space = UDI29KGlobalRegs; */
comment|/* OBSOLETE       From.Offset = (regno - GR96_REGNUM) + 96;; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if defined(GR64_REGNUM) */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   else if (regno>= GR64_REGNUM&& regno< GR64_REGNUM + 32) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       From.Space = UDI29KGlobalRegs; */
comment|/* OBSOLETE       From.Offset = (regno - GR64_REGNUM) + 64; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #endif /* GR64_REGNUM */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   else if (regno>= LR0_REGNUM&& regno< LR0_REGNUM + 128) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       From.Space = UDI29KLocalRegs; */
comment|/* OBSOLETE       From.Offset = (regno - LR0_REGNUM); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (regno>= FPE_REGNUM&& regno<= EXO_REGNUM) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       int val = -1; */
comment|/* OBSOLETE       /*supply_register(160 + (regno - FPE_REGNUM),(char *)&val); */
operator|*
operator|/
comment|/* OBSOLETE       supply_register (regno, (char *)&val); */
comment|/* OBSOLETE       return;			/* Pretend Success */
operator|*
operator|/
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       From.Space = UDI29KSpecialRegs; */
comment|/* OBSOLETE       From.Offset = regnum_to_srnum (regno); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (err = UDIRead (From,&To, Count, Size,&CountDone, HostEndian)) */
comment|/* OBSOLETE     error ("UDIRead() failed in udi_fetch_registers"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   supply_register (regno, (char *)&To); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (remote_debug) */
comment|/* OBSOLETE     fprintf_unfiltered (gdb_stdlog, "Fetching register %s = 0x%x\n", */
comment|/* OBSOLETE 			REGISTER_NAME (regno), To); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /*****************************************************************************/
operator|*
operator|/
comment|/* OBSOLETE /* Store a single register indicated by 'regno'.  */
comment|/* OBSOLETE  * Returns 0/-1 on success/failure.   */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE store_register (int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int result; */
comment|/* OBSOLETE   UDIUInt32 From; */
comment|/* OBSOLETE   UDIResource To; */
comment|/* OBSOLETE   UDICount Count = 1; */
comment|/* OBSOLETE   UDISizeT Size = 4; */
comment|/* OBSOLETE   UDICount CountDone; */
comment|/* OBSOLETE   UDIBool HostEndian = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   From = read_register (regno);	/* get data value */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (remote_debug) */
comment|/* OBSOLETE     fprintf_unfiltered (gdb_stdlog, "Storing register %s = 0x%x\n", */
comment|/* OBSOLETE 			REGISTER_NAME (regno), From); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (regno == GR1_REGNUM) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       To.Space = UDI29KGlobalRegs; */
comment|/* OBSOLETE       To.Offset = 1; */
comment|/* OBSOLETE       result = UDIWrite (&From, To, Count, Size,&CountDone, HostEndian); */
comment|/* OBSOLETE       /* Setting GR1 changes the numbers of all the locals, so invalidate the  */
comment|/* OBSOLETE        * register cache.  Do this *after* calling read_register, because we want  */
comment|/* OBSOLETE        * read_register to return the value that write_register has just stuffed  */
comment|/* OBSOLETE        * into the registers array, not the value of the register fetched from  */
comment|/* OBSOLETE        * the inferior.   */
comment|/* OBSOLETE        */
operator|*
operator|/
comment|/* OBSOLETE       registers_changed (); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE #if defined(GR64_REGNUM) */
comment|/* OBSOLETE   else if (regno>= GR64_REGNUM&& regno< GR64_REGNUM + 32) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       To.Space = UDI29KGlobalRegs; */
comment|/* OBSOLETE       To.Offset = (regno - GR64_REGNUM) + 64; */
comment|/* OBSOLETE       result = UDIWrite (&From, To, Count, Size,&CountDone, HostEndian); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE #endif /* GR64_REGNUM */
operator|*
operator|/
comment|/* OBSOLETE   else if (regno>= GR96_REGNUM&& regno< GR96_REGNUM + 32) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       To.Space = UDI29KGlobalRegs; */
comment|/* OBSOLETE       To.Offset = (regno - GR96_REGNUM) + 96; */
comment|/* OBSOLETE       result = UDIWrite (&From, To, Count, Size,&CountDone, HostEndian); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (regno>= LR0_REGNUM&& regno< LR0_REGNUM + 128) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       To.Space = UDI29KLocalRegs; */
comment|/* OBSOLETE       To.Offset = (regno - LR0_REGNUM); */
comment|/* OBSOLETE       result = UDIWrite (&From, To, Count, Size,&CountDone, HostEndian); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (regno>= FPE_REGNUM&& regno<= EXO_REGNUM) */
comment|/* OBSOLETE     return 0;			/* Pretend Success */
operator|*
operator|/
comment|/* OBSOLETE   else if (regno == PC_REGNUM) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       /* PC1 via UDI29KPC */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE       To.Space = UDI29KPC; */
comment|/* OBSOLETE       To.Offset = 0;		/* PC1 */
operator|*
operator|/
comment|/* OBSOLETE       result = UDIWrite (&From, To, Count, Size,&CountDone, HostEndian); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE       /* Writing to this loc actually changes the values of pc0& pc1 */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE       register_valid[PC_REGNUM] = 0;	/* pc1 */
operator|*
operator|/
comment|/* OBSOLETE       register_valid[NPC_REGNUM] = 0;	/* pc0 */
operator|*
operator|/
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     /* An unprotected or protected special register */
operator|*
operator|/
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       To.Space = UDI29KSpecialRegs; */
comment|/* OBSOLETE       To.Offset = regnum_to_srnum (regno); */
comment|/* OBSOLETE       result = UDIWrite (&From, To, Count, Size,&CountDone, HostEndian); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (result != 0) */
comment|/* OBSOLETE     error ("UDIWrite() failed in store_registers"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   return 0; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /********************************************************** REGNUM_TO_SRNUM */
operator|*
operator|/
comment|/* OBSOLETE /*  */
comment|/* OBSOLETE  * Convert a gdb special register number to a 29000 special register number. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE regnum_to_srnum (int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   switch (regno) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE     case VAB_REGNUM: */
comment|/* OBSOLETE       return (0); */
comment|/* OBSOLETE     case OPS_REGNUM: */
comment|/* OBSOLETE       return (1); */
comment|/* OBSOLETE     case CPS_REGNUM: */
comment|/* OBSOLETE       return (2); */
comment|/* OBSOLETE     case CFG_REGNUM: */
comment|/* OBSOLETE       return (3); */
comment|/* OBSOLETE     case CHA_REGNUM: */
comment|/* OBSOLETE       return (4); */
comment|/* OBSOLETE     case CHD_REGNUM: */
comment|/* OBSOLETE       return (5); */
comment|/* OBSOLETE     case CHC_REGNUM: */
comment|/* OBSOLETE       return (6); */
comment|/* OBSOLETE     case RBP_REGNUM: */
comment|/* OBSOLETE       return (7); */
comment|/* OBSOLETE     case TMC_REGNUM: */
comment|/* OBSOLETE       return (8); */
comment|/* OBSOLETE     case TMR_REGNUM: */
comment|/* OBSOLETE       return (9); */
comment|/* OBSOLETE     case NPC_REGNUM: */
comment|/* OBSOLETE       return (USE_SHADOW_PC ? (20) : (10)); */
comment|/* OBSOLETE     case PC_REGNUM: */
comment|/* OBSOLETE       return (USE_SHADOW_PC ? (21) : (11)); */
comment|/* OBSOLETE     case PC2_REGNUM: */
comment|/* OBSOLETE       return (USE_SHADOW_PC ? (22) : (12)); */
comment|/* OBSOLETE     case MMU_REGNUM: */
comment|/* OBSOLETE       return (13); */
comment|/* OBSOLETE     case LRU_REGNUM: */
comment|/* OBSOLETE       return (14); */
comment|/* OBSOLETE     case IPC_REGNUM: */
comment|/* OBSOLETE       return (128); */
comment|/* OBSOLETE     case IPA_REGNUM: */
comment|/* OBSOLETE       return (129); */
comment|/* OBSOLETE     case IPB_REGNUM: */
comment|/* OBSOLETE       return (130); */
comment|/* OBSOLETE     case Q_REGNUM: */
comment|/* OBSOLETE       return (131); */
comment|/* OBSOLETE     case ALU_REGNUM: */
comment|/* OBSOLETE       return (132); */
comment|/* OBSOLETE     case BP_REGNUM: */
comment|/* OBSOLETE       return (133); */
comment|/* OBSOLETE     case FC_REGNUM: */
comment|/* OBSOLETE       return (134); */
comment|/* OBSOLETE     case CR_REGNUM: */
comment|/* OBSOLETE       return (135); */
comment|/* OBSOLETE     case FPE_REGNUM: */
comment|/* OBSOLETE       return (160); */
comment|/* OBSOLETE     case INTE_REGNUM: */
comment|/* OBSOLETE       return (161); */
comment|/* OBSOLETE     case FPS_REGNUM: */
comment|/* OBSOLETE       return (162); */
comment|/* OBSOLETE     case EXO_REGNUM: */
comment|/* OBSOLETE       return (164); */
comment|/* OBSOLETE     default: */
comment|/* OBSOLETE       return (255);		/* Failure ? */
operator|*
operator|/
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /****************************************************************************/
operator|*
operator|/
comment|/* OBSOLETE /* */
comment|/* OBSOLETE  * Determine the Target memory space qualifier based on the addr.  */
comment|/* OBSOLETE  * FIXME: Can't distinguis I_ROM/D_ROM.   */
comment|/* OBSOLETE  * FIXME: Doesn't know anything about I_CACHE/D_CACHE. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static CPUSpace */
comment|/* OBSOLETE udi_memory_space (CORE_ADDR addr) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   UDIUInt32 tstart = IMemStart; */
comment|/* OBSOLETE   UDIUInt32 tend = tstart + IMemSize; */
comment|/* OBSOLETE   UDIUInt32 dstart = DMemStart; */
comment|/* OBSOLETE   UDIUInt32 dend = tstart + DMemSize; */
comment|/* OBSOLETE   UDIUInt32 rstart = RMemStart; */
comment|/* OBSOLETE   UDIUInt32 rend = tstart + RMemSize; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (((UDIUInt32) addr>= tstart)&& ((UDIUInt32) addr< tend)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       return UDI29KIRAMSpace; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (((UDIUInt32) addr>= dstart)&& ((UDIUInt32) addr< dend)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       return UDI29KDRAMSpace; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (((UDIUInt32) addr>= rstart)&& ((UDIUInt32) addr< rend)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       /* FIXME: how do we determine between D_ROM and I_ROM */
operator|*
operator|/
comment|/* OBSOLETE       return UDI29KIROMSpace; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else				/* FIXME: what do me do now? */
operator|*
operator|/
comment|/* OBSOLETE     return UDI29KDRAMSpace;	/* Hmmm! */
operator|*
operator|/
comment|/* OBSOLETE } */
comment|/* OBSOLETE /*********************************************************************** STUBS */
comment|/* OBSOLETE */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE void */
comment|/* OBSOLETE convert16 (void) */
comment|/* OBSOLETE {; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE void */
comment|/* OBSOLETE convert32 (void) */
comment|/* OBSOLETE {; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE struct ui_file *EchoFile = 0;	/* used for debugging */
operator|*
operator|/
comment|/* OBSOLETE int QuietMode = 0;		/* used for debugging */
operator|*
operator|/
comment|/* OBSOLETE
comment|*/
comment|/* OBSOLETE #ifdef NO_HIF_SUPPORT */
comment|/* OBSOLETE service_HIF (union msg_t *msg) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   return (0);			/* Emulate a failure */
operator|*
operator|/
comment|/* OBSOLETE } */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE
comment|*/
comment|/* OBSOLETE /* Target_ops vector.  Not static because there does not seem to be */
comment|/* OBSOLETE    any portable way to do a forward declaration of a static variable. */
comment|/* OBSOLETE    The RS/6000 doesn't like "extern" followed by "static"; SunOS */
comment|/* OBSOLETE    /bin/cc doesn't like "static" twice.  */
operator|*
operator|/
end_expr_stmt

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE struct target_ops udi_ops; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE static void */
end_comment

begin_comment
comment|/* OBSOLETE init_udi_ops (void) */
end_comment

begin_comment
comment|/* OBSOLETE { */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_shortname = "udi"; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_longname = "Remote UDI connected TIP"; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_doc = "Remote debug an AMD 29k using UDI socket connection to TIP process.\n\ */
end_comment

begin_comment
comment|/* OBSOLETE Arguments are\n\ */
end_comment

begin_comment
comment|/* OBSOLETE `configuration-id AF_INET hostname port-number'\n\ */
end_comment

begin_comment
comment|/* OBSOLETE To connect via the network, where hostname and port-number specify the\n\ */
end_comment

begin_comment
comment|/* OBSOLETE host and port where you can connect via UDI.\n\ */
end_comment

begin_comment
comment|/* OBSOLETE configuration-id is unused.\n\ */
end_comment

begin_comment
comment|/* OBSOLETE \n\ */
end_comment

begin_comment
comment|/* OBSOLETE `configuration-id AF_UNIX socket-name tip-program'\n\ */
end_comment

begin_comment
comment|/* OBSOLETE To connect using a local connection to the \"tip.exe\" program which is\n\ */
end_comment

begin_comment
comment|/* OBSOLETE     supplied by AMD.  If socket-name specifies an AF_UNIX socket then the\n\ */
end_comment

begin_comment
comment|/* OBSOLETE     tip program must already be started; connect to it using that socket.\n\ */
end_comment

begin_comment
comment|/* OBSOLETE     If not, start up tip-program, which should be the name of the tip\n\ */
end_comment

begin_comment
comment|/* OBSOLETE     program.  If appropriate, the PATH environment variable is searched.\n\ */
end_comment

begin_comment
comment|/* OBSOLETE     configuration-id is unused.\n\ */
end_comment

begin_comment
comment|/* OBSOLETE \n\ */
end_comment

begin_comment
comment|/* OBSOLETE `configuration-id'\n\ */
end_comment

begin_comment
comment|/* OBSOLETE     Look up the configuration in ./udi_soc or /etc/udi_soc, which\n\ */
end_comment

begin_comment
comment|/* OBSOLETE     are files containing lines in the above formats.  configuration-id is\n\ */
end_comment

begin_comment
comment|/* OBSOLETE     used to pick which line of the file to use."; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_open = udi_open; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_close = udi_close; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_attach = udi_attach; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_detach = udi_detach; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_resume = udi_resume; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_wait = udi_wait; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_fetch_registers = udi_fetch_registers; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_store_registers = udi_store_registers; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_prepare_to_store = udi_prepare_to_store; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_xfer_memory = udi_xfer_inferior_memory; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_files_info = udi_files_info; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_insert_breakpoint = udi_insert_breakpoint; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_remove_breakpoint = udi_remove_breakpoint; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_terminal_init = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_terminal_inferior = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_terminal_ours_for_output = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_terminal_ours = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_terminal_info = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_kill = udi_kill; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_load = udi_load; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_lookup_symbol = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_create_inferior = udi_create_inferior; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_mourn_inferior = udi_mourn; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_can_run = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_notice_signals = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_thread_alive = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_stop = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_stratum = process_stratum; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.DONT_USE = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_has_all_memory = 1; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_has_memory = 1; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_has_stack = 1; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_has_registers = 1; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_has_execution = 1; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_sections = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_sections_end = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   udi_ops.to_magic = OPS_MAGIC; */
end_comment

begin_comment
comment|/* OBSOLETE }; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE void */
end_comment

begin_comment
comment|/* OBSOLETE _initialize_remote_udi (void) */
end_comment

begin_comment
comment|/* OBSOLETE { */
end_comment

begin_comment
comment|/* OBSOLETE   init_udi_ops (); */
end_comment

begin_comment
comment|/* OBSOLETE   add_target (&udi_ops); */
end_comment

begin_comment
comment|/* OBSOLETE } */
end_comment

end_unit

