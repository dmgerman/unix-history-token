begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* OBSOLETE /* Acorn Risc Machine host machine support. */
end_comment

begin_comment
comment|/* OBSOLETE    Copyright (C) 1988, 1989, 1991 Free Software Foundation, Inc. */
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
comment|/* OBSOLETE    Boston, MA 02111-1307, USA.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE #include "defs.h" */
end_comment

begin_comment
comment|/* OBSOLETE #include "frame.h" */
end_comment

begin_comment
comment|/* OBSOLETE #include "inferior.h" */
end_comment

begin_comment
comment|/* OBSOLETE #include "opcode/arm.h" */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE #include<sys/param.h> */
end_comment

begin_comment
comment|/* OBSOLETE #include<sys/dir.h> */
end_comment

begin_comment
comment|/* OBSOLETE #include<signal.h> */
end_comment

begin_comment
comment|/* OBSOLETE #include<sys/ioctl.h> */
end_comment

begin_comment
comment|/* OBSOLETE #include<sys/ptrace.h> */
end_comment

begin_comment
comment|/* OBSOLETE #include<machine/reg.h> */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE #define N_TXTADDR(hdr) 0x8000 */
end_comment

begin_comment
comment|/* OBSOLETE #define N_DATADDR(hdr) (hdr.a_text + 0x8000) */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE #include "gdbcore.h" */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE #include<sys/user.h>		/* After a.out.h  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE #include<sys/file.h> */
end_comment

begin_comment
comment|/* OBSOLETE #include "gdb_stat.h" */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE #include<errno.h> */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE void */
end_comment

begin_comment
comment|/* OBSOLETE fetch_inferior_registers (regno) */
end_comment

begin_comment
comment|/* OBSOLETE      int regno;			/* Original value discarded *x/ */
end_comment

begin_comment
comment|/* OBSOLETE { */
end_comment

begin_comment
comment|/* OBSOLETE   register unsigned int regaddr; */
end_comment

begin_comment
comment|/* OBSOLETE   char buf[MAX_REGISTER_RAW_SIZE]; */
end_comment

begin_comment
comment|/* OBSOLETE   register int i; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   struct user u; */
end_comment

begin_comment
comment|/* OBSOLETE   unsigned int offset = (char *)&u.u_ar0 - (char *)&u; */
end_comment

begin_comment
comment|/* OBSOLETE   offset = ptrace (PT_READ_U, inferior_pid, (PTRACE_ARG3_TYPE) offset, 0) */
end_comment

begin_comment
comment|/* OBSOLETE     - KERNEL_U_ADDR; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   registers_fetched (); */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   for (regno = 0; regno< 16; regno++) */
end_comment

begin_comment
comment|/* OBSOLETE     { */
end_comment

begin_comment
comment|/* OBSOLETE       regaddr = offset + regno * 4; */
end_comment

begin_comment
comment|/* OBSOLETE       *(int *)&buf[0] = ptrace (PT_READ_U, inferior_pid, */
end_comment

begin_comment
comment|/* OBSOLETE 				 (PTRACE_ARG3_TYPE) regaddr, 0); */
end_comment

begin_comment
comment|/* OBSOLETE       if (regno == PC_REGNUM) */
end_comment

begin_comment
comment|/* OBSOLETE 	*(int *)&buf[0] = GET_PC_PART (*(int *)&buf[0]); */
end_comment

begin_comment
comment|/* OBSOLETE       supply_register (regno, buf); */
end_comment

begin_comment
comment|/* OBSOLETE     } */
end_comment

begin_comment
comment|/* OBSOLETE   *(int *)&buf[0] = ptrace (PT_READ_U, inferior_pid, */
end_comment

begin_comment
comment|/* OBSOLETE 			     (PTRACE_ARG3_TYPE) (offset + PC * 4), 0); */
end_comment

begin_comment
comment|/* OBSOLETE   supply_register (PS_REGNUM, buf);	/* set virtual register ps same as pc *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   /* read the floating point registers *x/ */
end_comment

begin_comment
comment|/* OBSOLETE   offset = (char *)&u.u_fp_regs - (char *)&u; */
end_comment

begin_comment
comment|/* OBSOLETE   *(int *) buf = ptrace (PT_READ_U, inferior_pid, (PTRACE_ARG3_TYPE) offset, 0); */
end_comment

begin_comment
comment|/* OBSOLETE   supply_register (FPS_REGNUM, buf); */
end_comment

begin_comment
comment|/* OBSOLETE   for (regno = 16; regno< 24; regno++) */
end_comment

begin_comment
comment|/* OBSOLETE     { */
end_comment

begin_comment
comment|/* OBSOLETE       regaddr = offset + 4 + 12 * (regno - 16); */
end_comment

begin_comment
comment|/* OBSOLETE       for (i = 0; i< 12; i += sizeof (int)) */
end_comment

begin_comment
comment|/* OBSOLETE 	 *(int *)&buf[i] = ptrace (PT_READ_U, inferior_pid, */
end_comment

begin_comment
comment|/* OBSOLETE 				      (PTRACE_ARG3_TYPE) (regaddr + i), 0); */
end_comment

begin_comment
comment|/* OBSOLETE       supply_register (regno, buf); */
end_comment

begin_comment
comment|/* OBSOLETE     } */
end_comment

begin_comment
comment|/* OBSOLETE } */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE /* Store our register values back into the inferior. */
end_comment

begin_comment
comment|/* OBSOLETE    If REGNO is -1, do this for all registers. */
end_comment

begin_comment
comment|/* OBSOLETE    Otherwise, REGNO specifies which register (so we can save time).  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE void */
end_comment

begin_comment
comment|/* OBSOLETE store_inferior_registers (regno) */
end_comment

begin_comment
comment|/* OBSOLETE      int regno; */
end_comment

begin_comment
comment|/* OBSOLETE { */
end_comment

begin_comment
comment|/* OBSOLETE   register unsigned int regaddr; */
end_comment

begin_comment
comment|/* OBSOLETE   char buf[80]; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   struct user u; */
end_comment

begin_comment
comment|/* OBSOLETE   unsigned long value; */
end_comment

begin_comment
comment|/* OBSOLETE   unsigned int offset = (char *)&u.u_ar0 - (char *)&u; */
end_comment

begin_comment
comment|/* OBSOLETE   offset = ptrace (PT_READ_U, inferior_pid, (PTRACE_ARG3_TYPE) offset, 0) */
end_comment

begin_comment
comment|/* OBSOLETE     - KERNEL_U_ADDR; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   if (regno>= 0) */
end_comment

begin_comment
comment|/* OBSOLETE     { */
end_comment

begin_comment
comment|/* OBSOLETE       if (regno>= 16) */
end_comment

begin_comment
comment|/* OBSOLETE 	return; */
end_comment

begin_comment
comment|/* OBSOLETE       regaddr = offset + 4 * regno; */
end_comment

begin_comment
comment|/* OBSOLETE       errno = 0; */
end_comment

begin_comment
comment|/* OBSOLETE       value = read_register (regno); */
end_comment

begin_comment
comment|/* OBSOLETE       if (regno == PC_REGNUM) */
end_comment

begin_comment
comment|/* OBSOLETE 	value = SET_PC_PART (read_register (PS_REGNUM), value); */
end_comment

begin_comment
comment|/* OBSOLETE       ptrace (PT_WRITE_U, inferior_pid, (PTRACE_ARG3_TYPE) regaddr, value); */
end_comment

begin_comment
comment|/* OBSOLETE       if (errno != 0) */
end_comment

begin_comment
comment|/* OBSOLETE 	{ */
end_comment

begin_comment
comment|/* OBSOLETE 	  sprintf (buf, "writing register number %d", regno); */
end_comment

begin_comment
comment|/* OBSOLETE 	  perror_with_name (buf); */
end_comment

begin_comment
comment|/* OBSOLETE 	} */
end_comment

begin_comment
comment|/* OBSOLETE     } */
end_comment

begin_comment
comment|/* OBSOLETE   else */
end_comment

begin_comment
comment|/* OBSOLETE     for (regno = 0; regno< 15; regno++) */
end_comment

begin_comment
comment|/* OBSOLETE       { */
end_comment

begin_comment
comment|/* OBSOLETE 	regaddr = offset + regno * 4; */
end_comment

begin_comment
comment|/* OBSOLETE 	errno = 0; */
end_comment

begin_comment
comment|/* OBSOLETE 	value = read_register (regno); */
end_comment

begin_comment
comment|/* OBSOLETE 	if (regno == PC_REGNUM) */
end_comment

begin_comment
comment|/* OBSOLETE 	  value = SET_PC_PART (read_register (PS_REGNUM), value); */
end_comment

begin_comment
comment|/* OBSOLETE 	ptrace (6, inferior_pid, (PTRACE_ARG3_TYPE) regaddr, value); */
end_comment

begin_comment
comment|/* OBSOLETE 	if (errno != 0) */
end_comment

begin_comment
comment|/* OBSOLETE 	  { */
end_comment

begin_comment
comment|/* OBSOLETE 	    sprintf (buf, "writing all regs, number %d", regno); */
end_comment

begin_comment
comment|/* OBSOLETE 	    perror_with_name (buf); */
end_comment

begin_comment
comment|/* OBSOLETE 	  } */
end_comment

begin_comment
comment|/* OBSOLETE       } */
end_comment

begin_comment
comment|/* OBSOLETE } */
end_comment

begin_comment
comment|/* OBSOLETE
comment|*/
end_comment

begin_comment
comment|/* OBSOLETE /* Work with core dump and executable files, for GDB.  */
end_comment

begin_comment
comment|/* OBSOLETE    This code would be in corefile.c if it weren't machine-dependent. *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE /* Structure to describe the chain of shared libraries used */
end_comment

begin_comment
comment|/* OBSOLETE    by the execfile. */
end_comment

begin_comment
comment|/* OBSOLETE    e.g. prog shares Xt which shares X11 which shares c. *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE struct shared_library */
end_comment

begin_comment
comment|/* OBSOLETE { */
end_comment

begin_comment
comment|/* OBSOLETE   struct exec_header header; */
end_comment

begin_comment
comment|/* OBSOLETE   char name[SHLIBLEN]; */
end_comment

begin_comment
comment|/* OBSOLETE   CORE_ADDR text_start;		/* CORE_ADDR of 1st byte of text, this file *x/ */
end_comment

begin_comment
comment|/* OBSOLETE   long data_offset;		/* offset of data section in file *x/ */
end_comment

begin_comment
comment|/* OBSOLETE   int chan;			/* file descriptor for the file *x/ */
end_comment

begin_comment
comment|/* OBSOLETE   struct shared_library *shares;	/* library this one shares *x/ */
end_comment

begin_comment
comment|/* OBSOLETE }; */
end_comment

begin_comment
comment|/* OBSOLETE static struct shared_library *shlib = 0; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE /* Hook for `exec_file_command' command to call.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE extern void (*exec_file_display_hook) (); */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE static CORE_ADDR unshared_text_start; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE /* extended header from exec file (for shared library info) *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE static struct exec_header exec_header; */
end_comment

begin_comment
comment|/* OBSOLETE
comment|*/
end_comment

begin_comment
comment|/* OBSOLETE void */
end_comment

begin_comment
comment|/* OBSOLETE core_file_command (filename, from_tty) */
end_comment

begin_comment
comment|/* OBSOLETE      char *filename; */
end_comment

begin_comment
comment|/* OBSOLETE      int from_tty; */
end_comment

begin_comment
comment|/* OBSOLETE { */
end_comment

begin_comment
comment|/* OBSOLETE   int val; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   /* Discard all vestiges of any previous core file */
end_comment

begin_comment
comment|/* OBSOLETE      and mark data and stack spaces as empty.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   if (corefile) */
end_comment

begin_comment
comment|/* OBSOLETE     free (corefile); */
end_comment

begin_comment
comment|/* OBSOLETE   corefile = 0; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   if (corechan>= 0) */
end_comment

begin_comment
comment|/* OBSOLETE     close (corechan); */
end_comment

begin_comment
comment|/* OBSOLETE   corechan = -1; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   data_start = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   data_end = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   stack_start = STACK_END_ADDR; */
end_comment

begin_comment
comment|/* OBSOLETE   stack_end = STACK_END_ADDR; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   /* Now, if a new core file was specified, open it and digest it.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   if (filename) */
end_comment

begin_comment
comment|/* OBSOLETE     { */
end_comment

begin_comment
comment|/* OBSOLETE       filename = tilde_expand (filename); */
end_comment

begin_comment
comment|/* OBSOLETE       make_cleanup (free, filename); */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE       if (have_inferior_p ()) */
end_comment

begin_comment
comment|/* OBSOLETE 	error ("To look at a core file, you must kill the program with \"kill\"."); */
end_comment

begin_comment
comment|/* OBSOLETE       corechan = open (filename, O_RDONLY, 0); */
end_comment

begin_comment
comment|/* OBSOLETE       if (corechan< 0) */
end_comment

begin_comment
comment|/* OBSOLETE 	perror_with_name (filename); */
end_comment

begin_comment
comment|/* OBSOLETE       /* 4.2-style (and perhaps also sysV-style) core dump file.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE       { */
end_comment

begin_comment
comment|/* OBSOLETE 	struct user u; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	unsigned int reg_offset, fp_reg_offset; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	val = myread (corechan,&u, sizeof u); */
end_comment

begin_comment
comment|/* OBSOLETE 	if (val< 0) */
end_comment

begin_comment
comment|/* OBSOLETE 	  perror_with_name ("Not a core file: reading upage"); */
end_comment

begin_comment
comment|/* OBSOLETE 	if (val != sizeof u) */
end_comment

begin_comment
comment|/* OBSOLETE 	  error ("Not a core file: could only read %d bytes", val); */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	/* We are depending on exec_file_command having been called */
end_comment

begin_comment
comment|/* OBSOLETE 	   previously to set exec_data_start.  Since the executable */
end_comment

begin_comment
comment|/* OBSOLETE 	   and the core file share the same text segment, the address */
end_comment

begin_comment
comment|/* OBSOLETE 	   of the data segment will be the same in both.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE 	data_start = exec_data_start; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	data_end = data_start + NBPG * u.u_dsize; */
end_comment

begin_comment
comment|/* OBSOLETE 	stack_start = stack_end - NBPG * u.u_ssize; */
end_comment

begin_comment
comment|/* OBSOLETE 	data_offset = NBPG * UPAGES; */
end_comment

begin_comment
comment|/* OBSOLETE 	stack_offset = NBPG * (UPAGES + u.u_dsize); */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	/* Some machines put an absolute address in here and some put */
end_comment

begin_comment
comment|/* OBSOLETE 	   the offset in the upage of the regs.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE 	reg_offset = (int) u.u_ar0; */
end_comment

begin_comment
comment|/* OBSOLETE 	if (reg_offset> NBPG * UPAGES) */
end_comment

begin_comment
comment|/* OBSOLETE 	  reg_offset -= KERNEL_U_ADDR; */
end_comment

begin_comment
comment|/* OBSOLETE 	fp_reg_offset = (char *)&u.u_fp_regs - (char *)&u; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	/* I don't know where to find this info. */
end_comment

begin_comment
comment|/* OBSOLETE 	   So, for now, mark it as not available.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE 	N_SET_MAGIC (core_aouthdr, 0); */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	/* Read the register values out of the core file and store */
end_comment

begin_comment
comment|/* OBSOLETE 	   them where `read_register' will find them.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	{ */
end_comment

begin_comment
comment|/* OBSOLETE 	  register int regno; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	  for (regno = 0; regno< NUM_REGS; regno++) */
end_comment

begin_comment
comment|/* OBSOLETE 	    { */
end_comment

begin_comment
comment|/* OBSOLETE 	      char buf[MAX_REGISTER_RAW_SIZE]; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	      if (regno< 16) */
end_comment

begin_comment
comment|/* OBSOLETE 		val = lseek (corechan, reg_offset + 4 * regno, 0); */
end_comment

begin_comment
comment|/* OBSOLETE 	      else if (regno< 24) */
end_comment

begin_comment
comment|/* OBSOLETE 		val = lseek (corechan, fp_reg_offset + 4 + 12 * (regno - 24), 0); */
end_comment

begin_comment
comment|/* OBSOLETE 	      else if (regno == 24) */
end_comment

begin_comment
comment|/* OBSOLETE 		val = lseek (corechan, fp_reg_offset, 0); */
end_comment

begin_comment
comment|/* OBSOLETE 	      else if (regno == 25) */
end_comment

begin_comment
comment|/* OBSOLETE 		val = lseek (corechan, reg_offset + 4 * PC, 0); */
end_comment

begin_comment
comment|/* OBSOLETE 	      if (val< 0 */
end_comment

begin_comment
comment|/* OBSOLETE 		  || (val = myread (corechan, buf, sizeof buf))< 0) */
end_comment

begin_comment
comment|/* OBSOLETE 		{ */
end_comment

begin_comment
comment|/* OBSOLETE 		  char *buffer = (char *) alloca (strlen (REGISTER_NAME (regno)) */
end_comment

begin_comment
comment|/* OBSOLETE 						  + 30); */
end_comment

begin_comment
comment|/* OBSOLETE 		  strcpy (buffer, "Reading register "); */
end_comment

begin_comment
comment|/* OBSOLETE 		  strcat (buffer, REGISTER_NAME (regno)); */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 		  perror_with_name (buffer); */
end_comment

begin_comment
comment|/* OBSOLETE 		} */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	      if (regno == PC_REGNUM) */
end_comment

begin_comment
comment|/* OBSOLETE 		*(int *) buf = GET_PC_PART (*(int *) buf); */
end_comment

begin_comment
comment|/* OBSOLETE 	      supply_register (regno, buf); */
end_comment

begin_comment
comment|/* OBSOLETE 	    } */
end_comment

begin_comment
comment|/* OBSOLETE 	} */
end_comment

begin_comment
comment|/* OBSOLETE       } */
end_comment

begin_comment
comment|/* OBSOLETE       if (filename[0] == '/') */
end_comment

begin_comment
comment|/* OBSOLETE 	corefile = savestring (filename, strlen (filename)); */
end_comment

begin_comment
comment|/* OBSOLETE       else */
end_comment

begin_comment
comment|/* OBSOLETE 	{ */
end_comment

begin_comment
comment|/* OBSOLETE 	  corefile = concat (current_directory, "/", filename, NULL); */
end_comment

begin_comment
comment|/* OBSOLETE 	} */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE       flush_cached_frames (); */
end_comment

begin_comment
comment|/* OBSOLETE       select_frame (get_current_frame (), 0); */
end_comment

begin_comment
comment|/* OBSOLETE       validate_files (); */
end_comment

begin_comment
comment|/* OBSOLETE     } */
end_comment

begin_comment
comment|/* OBSOLETE   else if (from_tty) */
end_comment

begin_comment
comment|/* OBSOLETE     printf ("No core file now.\n"); */
end_comment

begin_comment
comment|/* OBSOLETE } */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE #if 0 */
end_comment

begin_comment
comment|/* OBSOLETE /* Work with core dump and executable files, for GDB.  */
end_comment

begin_comment
comment|/* OBSOLETE    This code would be in corefile.c if it weren't machine-dependent. *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE /* Structure to describe the chain of shared libraries used */
end_comment

begin_comment
comment|/* OBSOLETE    by the execfile. */
end_comment

begin_comment
comment|/* OBSOLETE    e.g. prog shares Xt which shares X11 which shares c. *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE struct shared_library */
end_comment

begin_comment
comment|/* OBSOLETE { */
end_comment

begin_comment
comment|/* OBSOLETE   struct exec_header header; */
end_comment

begin_comment
comment|/* OBSOLETE   char name[SHLIBLEN]; */
end_comment

begin_comment
comment|/* OBSOLETE   CORE_ADDR text_start;		/* CORE_ADDR of 1st byte of text, this file *x/ */
end_comment

begin_comment
comment|/* OBSOLETE   long data_offset;		/* offset of data section in file *x/ */
end_comment

begin_comment
comment|/* OBSOLETE   int chan;			/* file descriptor for the file *x/ */
end_comment

begin_comment
comment|/* OBSOLETE   struct shared_library *shares;	/* library this one shares *x/ */
end_comment

begin_comment
comment|/* OBSOLETE }; */
end_comment

begin_comment
comment|/* OBSOLETE static struct shared_library *shlib = 0; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE /* Hook for `exec_file_command' command to call.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE extern void (*exec_file_display_hook) (); */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE static CORE_ADDR unshared_text_start; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE /* extended header from exec file (for shared library info) *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE static struct exec_header exec_header; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE void */
end_comment

begin_comment
comment|/* OBSOLETE exec_file_command (filename, from_tty) */
end_comment

begin_comment
comment|/* OBSOLETE      char *filename; */
end_comment

begin_comment
comment|/* OBSOLETE      int from_tty; */
end_comment

begin_comment
comment|/* OBSOLETE { */
end_comment

begin_comment
comment|/* OBSOLETE   int val; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   /* Eliminate all traces of old exec file. */
end_comment

begin_comment
comment|/* OBSOLETE      Mark text segment as empty.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   if (execfile) */
end_comment

begin_comment
comment|/* OBSOLETE     free (execfile); */
end_comment

begin_comment
comment|/* OBSOLETE   execfile = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   data_start = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   data_end -= exec_data_start; */
end_comment

begin_comment
comment|/* OBSOLETE   text_start = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   unshared_text_start = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   text_end = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   exec_data_start = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   exec_data_end = 0; */
end_comment

begin_comment
comment|/* OBSOLETE   if (execchan>= 0) */
end_comment

begin_comment
comment|/* OBSOLETE     close (execchan); */
end_comment

begin_comment
comment|/* OBSOLETE   execchan = -1; */
end_comment

begin_comment
comment|/* OBSOLETE   if (shlib) */
end_comment

begin_comment
comment|/* OBSOLETE     { */
end_comment

begin_comment
comment|/* OBSOLETE       close_shared_library (shlib); */
end_comment

begin_comment
comment|/* OBSOLETE       shlib = 0; */
end_comment

begin_comment
comment|/* OBSOLETE     } */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   /* Now open and digest the file the user requested, if any.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   if (filename) */
end_comment

begin_comment
comment|/* OBSOLETE     { */
end_comment

begin_comment
comment|/* OBSOLETE       filename = tilde_expand (filename); */
end_comment

begin_comment
comment|/* OBSOLETE       make_cleanup (free, filename); */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE       execchan = openp (getenv ("PATH"), 1, filename, O_RDONLY, 0, */
end_comment

begin_comment
comment|/* OBSOLETE&execfile); */
end_comment

begin_comment
comment|/* OBSOLETE       if (execchan< 0) */
end_comment

begin_comment
comment|/* OBSOLETE 	perror_with_name (filename); */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE       { */
end_comment

begin_comment
comment|/* OBSOLETE 	struct stat st_exec; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE #ifdef HEADER_SEEK_FD */
end_comment

begin_comment
comment|/* OBSOLETE 	HEADER_SEEK_FD (execchan); */
end_comment

begin_comment
comment|/* OBSOLETE #endif */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	val = myread (execchan,&exec_header, sizeof exec_header); */
end_comment

begin_comment
comment|/* OBSOLETE 	exec_aouthdr = exec_header.a_exec; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	if (val< 0) */
end_comment

begin_comment
comment|/* OBSOLETE 	  perror_with_name (filename); */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	text_start = 0x8000; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	/* Look for shared library if needed *x/ */
end_comment

begin_comment
comment|/* OBSOLETE 	if (exec_header.a_exec.a_magic& MF_USES_SL) */
end_comment

begin_comment
comment|/* OBSOLETE 	  shlib = open_shared_library (exec_header.a_shlibname, text_start); */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	text_offset = N_TXTOFF (exec_aouthdr); */
end_comment

begin_comment
comment|/* OBSOLETE 	exec_data_offset = N_TXTOFF (exec_aouthdr) + exec_aouthdr.a_text; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	if (shlib) */
end_comment

begin_comment
comment|/* OBSOLETE 	  { */
end_comment

begin_comment
comment|/* OBSOLETE 	    unshared_text_start = shared_text_end (shlib)& ~0x7fff; */
end_comment

begin_comment
comment|/* OBSOLETE 	    stack_start = shlib->header.a_exec.a_sldatabase; */
end_comment

begin_comment
comment|/* OBSOLETE 	    stack_end = STACK_END_ADDR; */
end_comment

begin_comment
comment|/* OBSOLETE 	  } */
end_comment

begin_comment
comment|/* OBSOLETE 	else */
end_comment

begin_comment
comment|/* OBSOLETE 	  unshared_text_start = 0x8000; */
end_comment

begin_comment
comment|/* OBSOLETE 	text_end = unshared_text_start + exec_aouthdr.a_text; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	exec_data_start = unshared_text_start + exec_aouthdr.a_text; */
end_comment

begin_comment
comment|/* OBSOLETE 	exec_data_end = exec_data_start + exec_aouthdr.a_data; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	data_start = exec_data_start; */
end_comment

begin_comment
comment|/* OBSOLETE 	data_end += exec_data_start; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE 	fstat (execchan,&st_exec); */
end_comment

begin_comment
comment|/* OBSOLETE 	exec_mtime = st_exec.st_mtime; */
end_comment

begin_comment
comment|/* OBSOLETE       } */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE       validate_files (); */
end_comment

begin_comment
comment|/* OBSOLETE     } */
end_comment

begin_comment
comment|/* OBSOLETE   else if (from_tty) */
end_comment

begin_comment
comment|/* OBSOLETE     printf ("No executable file now.\n"); */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   /* Tell display code (if any) about the changed file name.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE   if (exec_file_display_hook) */
end_comment

begin_comment
comment|/* OBSOLETE     (*exec_file_display_hook) (filename); */
end_comment

begin_comment
comment|/* OBSOLETE } */
end_comment

begin_comment
comment|/* OBSOLETE #endif */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE #if 0 */
end_comment

begin_comment
comment|/* OBSOLETE /* Read from the program's memory (except for inferior processes). */
end_comment

begin_comment
comment|/* OBSOLETE    This function is misnamed, since it only reads, never writes; and */
end_comment

begin_comment
comment|/* OBSOLETE    since it will use the core file and/or executable file as necessary. */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE    It should be extended to write as well as read, FIXME, for patching files. */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE    Return 0 if address could be read, EIO if addresss out of bounds.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE int */
end_comment

begin_comment
comment|/* OBSOLETE xfer_core_file (memaddr, myaddr, len) */
end_comment

begin_comment
comment|/* OBSOLETE      CORE_ADDR memaddr; */
end_comment

begin_comment
comment|/* OBSOLETE      char *myaddr; */
end_comment

begin_comment
comment|/* OBSOLETE      int len; */
end_comment

begin_comment
comment|/* OBSOLETE { */
end_comment

begin_comment
comment|/* OBSOLETE   register int i; */
end_comment

begin_comment
comment|/* OBSOLETE   register int val; */
end_comment

begin_comment
comment|/* OBSOLETE   int xferchan; */
end_comment

begin_comment
comment|/* OBSOLETE   char **xferfile; */
end_comment

begin_comment
comment|/* OBSOLETE   int fileptr; */
end_comment

begin_comment
comment|/* OBSOLETE   int returnval = 0; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   while (len> 0) */
end_comment

begin_comment
comment|/* OBSOLETE     { */
end_comment

begin_comment
comment|/* OBSOLETE       xferfile = 0; */
end_comment

begin_comment
comment|/* OBSOLETE       xferchan = 0; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE       /* Determine which file the next bunch of addresses reside in, */
end_comment

begin_comment
comment|/* OBSOLETE          and where in the file.  Set the file's read/write pointer */
end_comment

begin_comment
comment|/* OBSOLETE          to point at the proper place for the desired address */
end_comment

begin_comment
comment|/* OBSOLETE          and set xferfile and xferchan for the correct file. */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE          If desired address is nonexistent, leave them zero. */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE          i is set to the number of bytes that can be handled */
end_comment

begin_comment
comment|/* OBSOLETE          along with the next address. */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE          We put the most likely tests first for efficiency.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE       /* Note that if there is no core file */
end_comment

begin_comment
comment|/* OBSOLETE          data_start and data_end are equal.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE       if (memaddr>= data_start&& memaddr< data_end) */
end_comment

begin_comment
comment|/* OBSOLETE 	{ */
end_comment

begin_comment
comment|/* OBSOLETE 	  i = min (len, data_end - memaddr); */
end_comment

begin_comment
comment|/* OBSOLETE 	  fileptr = memaddr - data_start + data_offset; */
end_comment

begin_comment
comment|/* OBSOLETE 	  xferfile =&corefile; */
end_comment

begin_comment
comment|/* OBSOLETE 	  xferchan = corechan; */
end_comment

begin_comment
comment|/* OBSOLETE 	} */
end_comment

begin_comment
comment|/* OBSOLETE       /* Note that if there is no core file */
end_comment

begin_comment
comment|/* OBSOLETE          stack_start and stack_end define the shared library data.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE       else if (memaddr>= stack_start&& memaddr< stack_end) */
end_comment

begin_comment
comment|/* OBSOLETE 	{ */
end_comment

begin_comment
comment|/* OBSOLETE 	  if (corechan< 0) */
end_comment

begin_comment
comment|/* OBSOLETE 	    { */
end_comment

begin_comment
comment|/* OBSOLETE 	      struct shared_library *lib; */
end_comment

begin_comment
comment|/* OBSOLETE 	      for (lib = shlib; lib; lib = lib->shares) */
end_comment

begin_comment
comment|/* OBSOLETE 		if (memaddr>= lib->header.a_exec.a_sldatabase&& */
end_comment

begin_comment
comment|/* OBSOLETE 		    memaddr< lib->header.a_exec.a_sldatabase + */
end_comment

begin_comment
comment|/* OBSOLETE 		    lib->header.a_exec.a_data) */
end_comment

begin_comment
comment|/* OBSOLETE 		  break; */
end_comment

begin_comment
comment|/* OBSOLETE 	      if (lib) */
end_comment

begin_comment
comment|/* OBSOLETE 		{ */
end_comment

begin_comment
comment|/* OBSOLETE 		  i = min (len, lib->header.a_exec.a_sldatabase + */
end_comment

begin_comment
comment|/* OBSOLETE 			   lib->header.a_exec.a_data - memaddr); */
end_comment

begin_comment
comment|/* OBSOLETE 		  fileptr = lib->data_offset + memaddr - */
end_comment

begin_comment
comment|/* OBSOLETE 		    lib->header.a_exec.a_sldatabase; */
end_comment

begin_comment
comment|/* OBSOLETE 		  xferfile = execfile; */
end_comment

begin_comment
comment|/* OBSOLETE 		  xferchan = lib->chan; */
end_comment

begin_comment
comment|/* OBSOLETE 		} */
end_comment

begin_comment
comment|/* OBSOLETE 	    } */
end_comment

begin_comment
comment|/* OBSOLETE 	  else */
end_comment

begin_comment
comment|/* OBSOLETE 	    { */
end_comment

begin_comment
comment|/* OBSOLETE 	      i = min (len, stack_end - memaddr); */
end_comment

begin_comment
comment|/* OBSOLETE 	      fileptr = memaddr - stack_start + stack_offset; */
end_comment

begin_comment
comment|/* OBSOLETE 	      xferfile =&corefile; */
end_comment

begin_comment
comment|/* OBSOLETE 	      xferchan = corechan; */
end_comment

begin_comment
comment|/* OBSOLETE 	    } */
end_comment

begin_comment
comment|/* OBSOLETE 	} */
end_comment

begin_comment
comment|/* OBSOLETE       else if (corechan< 0 */
end_comment

begin_comment
comment|/* OBSOLETE&& memaddr>= exec_data_start&& memaddr< exec_data_end) */
end_comment

begin_comment
comment|/* OBSOLETE 	{ */
end_comment

begin_comment
comment|/* OBSOLETE 	  i = min (len, exec_data_end - memaddr); */
end_comment

begin_comment
comment|/* OBSOLETE 	  fileptr = memaddr - exec_data_start + exec_data_offset; */
end_comment

begin_comment
comment|/* OBSOLETE 	  xferfile =&execfile; */
end_comment

begin_comment
comment|/* OBSOLETE 	  xferchan = execchan; */
end_comment

begin_comment
comment|/* OBSOLETE 	} */
end_comment

begin_comment
comment|/* OBSOLETE       else if (memaddr>= text_start&& memaddr< text_end) */
end_comment

begin_comment
comment|/* OBSOLETE 	{ */
end_comment

begin_comment
comment|/* OBSOLETE 	  struct shared_library *lib; */
end_comment

begin_comment
comment|/* OBSOLETE 	  for (lib = shlib; lib; lib = lib->shares) */
end_comment

begin_comment
comment|/* OBSOLETE 	    if (memaddr>= lib->text_start&& */
end_comment

begin_comment
comment|/* OBSOLETE 		memaddr< lib->text_start + lib->header.a_exec.a_text) */
end_comment

begin_comment
comment|/* OBSOLETE 	      break; */
end_comment

begin_comment
comment|/* OBSOLETE 	  if (lib) */
end_comment

begin_comment
comment|/* OBSOLETE 	    { */
end_comment

begin_comment
comment|/* OBSOLETE 	      i = min (len, lib->header.a_exec.a_text + */
end_comment

begin_comment
comment|/* OBSOLETE 		       lib->text_start - memaddr); */
end_comment

begin_comment
comment|/* OBSOLETE 	      fileptr = memaddr - lib->text_start + text_offset; */
end_comment

begin_comment
comment|/* OBSOLETE 	      xferfile =&execfile; */
end_comment

begin_comment
comment|/* OBSOLETE 	      xferchan = lib->chan; */
end_comment

begin_comment
comment|/* OBSOLETE 	    } */
end_comment

begin_comment
comment|/* OBSOLETE 	  else */
end_comment

begin_comment
comment|/* OBSOLETE 	    { */
end_comment

begin_comment
comment|/* OBSOLETE 	      i = min (len, text_end - memaddr); */
end_comment

begin_comment
comment|/* OBSOLETE 	      fileptr = memaddr - unshared_text_start + text_offset; */
end_comment

begin_comment
comment|/* OBSOLETE 	      xferfile =&execfile; */
end_comment

begin_comment
comment|/* OBSOLETE 	      xferchan = execchan; */
end_comment

begin_comment
comment|/* OBSOLETE 	    } */
end_comment

begin_comment
comment|/* OBSOLETE 	} */
end_comment

begin_comment
comment|/* OBSOLETE       else if (memaddr< text_start) */
end_comment

begin_comment
comment|/* OBSOLETE 	{ */
end_comment

begin_comment
comment|/* OBSOLETE 	  i = min (len, text_start - memaddr); */
end_comment

begin_comment
comment|/* OBSOLETE 	} */
end_comment

begin_comment
comment|/* OBSOLETE       else if (memaddr>= text_end */
end_comment

begin_comment
comment|/* OBSOLETE&& memaddr< (corechan>= 0 ? data_start : exec_data_start)) */
end_comment

begin_comment
comment|/* OBSOLETE 	{ */
end_comment

begin_comment
comment|/* OBSOLETE 	  i = min (len, data_start - memaddr); */
end_comment

begin_comment
comment|/* OBSOLETE 	} */
end_comment

begin_comment
comment|/* OBSOLETE       else if (corechan>= 0 */
end_comment

begin_comment
comment|/* OBSOLETE&& memaddr>= data_end&& memaddr< stack_start) */
end_comment

begin_comment
comment|/* OBSOLETE 	{ */
end_comment

begin_comment
comment|/* OBSOLETE 	  i = min (len, stack_start - memaddr); */
end_comment

begin_comment
comment|/* OBSOLETE 	} */
end_comment

begin_comment
comment|/* OBSOLETE       else if (corechan< 0&& memaddr>= exec_data_end) */
end_comment

begin_comment
comment|/* OBSOLETE 	{ */
end_comment

begin_comment
comment|/* OBSOLETE 	  i = min (len, -memaddr); */
end_comment

begin_comment
comment|/* OBSOLETE 	} */
end_comment

begin_comment
comment|/* OBSOLETE       else if (memaddr>= stack_end&& stack_end != 0) */
end_comment

begin_comment
comment|/* OBSOLETE 	{ */
end_comment

begin_comment
comment|/* OBSOLETE 	  i = min (len, -memaddr); */
end_comment

begin_comment
comment|/* OBSOLETE 	} */
end_comment

begin_comment
comment|/* OBSOLETE       else */
end_comment

begin_comment
comment|/* OBSOLETE 	{ */
end_comment

begin_comment
comment|/* OBSOLETE 	  /* Address did not classify into one of the known ranges. */
end_comment

begin_comment
comment|/* OBSOLETE 	     This shouldn't happen; we catch the endpoints.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE 	  internal_error ("Bad case logic in xfer_core_file."); */
end_comment

begin_comment
comment|/* OBSOLETE 	} */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE       /* Now we know which file to use. */
end_comment

begin_comment
comment|/* OBSOLETE          Set up its pointer and transfer the data.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE       if (xferfile) */
end_comment

begin_comment
comment|/* OBSOLETE 	{ */
end_comment

begin_comment
comment|/* OBSOLETE 	  if (*xferfile == 0) */
end_comment

begin_comment
comment|/* OBSOLETE 	    if (xferfile ==&execfile) */
end_comment

begin_comment
comment|/* OBSOLETE 	      error ("No program file to examine."); */
end_comment

begin_comment
comment|/* OBSOLETE 	    else */
end_comment

begin_comment
comment|/* OBSOLETE 	      error ("No core dump file or running program to examine."); */
end_comment

begin_comment
comment|/* OBSOLETE 	  val = lseek (xferchan, fileptr, 0); */
end_comment

begin_comment
comment|/* OBSOLETE 	  if (val< 0) */
end_comment

begin_comment
comment|/* OBSOLETE 	    perror_with_name (*xferfile); */
end_comment

begin_comment
comment|/* OBSOLETE 	  val = myread (xferchan, myaddr, i); */
end_comment

begin_comment
comment|/* OBSOLETE 	  if (val< 0) */
end_comment

begin_comment
comment|/* OBSOLETE 	    perror_with_name (*xferfile); */
end_comment

begin_comment
comment|/* OBSOLETE 	} */
end_comment

begin_comment
comment|/* OBSOLETE       /* If this address is for nonexistent memory, */
end_comment

begin_comment
comment|/* OBSOLETE          read zeros if reading, or do nothing if writing. */
end_comment

begin_comment
comment|/* OBSOLETE          Actually, we never right.  *x/ */
end_comment

begin_comment
comment|/* OBSOLETE       else */
end_comment

begin_comment
comment|/* OBSOLETE 	{ */
end_comment

begin_comment
comment|/* OBSOLETE 	  memset (myaddr, '\0', i); */
end_comment

begin_comment
comment|/* OBSOLETE 	  returnval = EIO; */
end_comment

begin_comment
comment|/* OBSOLETE 	} */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE       memaddr += i; */
end_comment

begin_comment
comment|/* OBSOLETE       myaddr += i; */
end_comment

begin_comment
comment|/* OBSOLETE       len -= i; */
end_comment

begin_comment
comment|/* OBSOLETE     } */
end_comment

begin_comment
comment|/* OBSOLETE   return returnval; */
end_comment

begin_comment
comment|/* OBSOLETE } */
end_comment

begin_comment
comment|/* OBSOLETE #endif */
end_comment

end_unit

