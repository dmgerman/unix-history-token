begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface between the opcode library and its callers.    Written by Cygnus Support, 1993.     The opcode library (libopcodes.a) provides instruction decoders for    a large variety of instruction sets, callable with an identical    interface, for making instruction-processing programs more independent    of the instruction set being processed.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*fprintf_ftype
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_enum
enum|enum
name|dis_insn_type
block|{
name|dis_noninsn
block|,
comment|/* Not a valid instruction */
name|dis_nonbranch
block|,
comment|/* Not a branch instruction */
name|dis_branch
block|,
comment|/* Unconditional branch */
name|dis_condbranch
block|,
comment|/* Conditional branch */
name|dis_jsr
block|,
comment|/* Jump to subroutine */
name|dis_condjsr
block|,
comment|/* Conditional jump to subroutine */
name|dis_dref
block|,
comment|/* Data reference instruction */
name|dis_dref2
block|,
comment|/* Two data references in instruction */
block|}
enum|;
end_enum

begin_comment
comment|/* This struct is passed into the instruction decoding routine,     and is passed back out into each callback.  The various fields are used    for conveying information from your main routine into your callbacks,    for passing information into the instruction decoders (such as the    addresses of the callback functions), or for passing information    back from the instruction decoders to their callers.     It must be initialized before it is first passed; this can be done    by hand, or using one of the initialization macros below.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|disassemble_info
block|{
name|fprintf_ftype
name|fprintf_func
decl_stmt|;
name|FILE
modifier|*
name|stream
decl_stmt|;
name|PTR
name|application_data
decl_stmt|;
comment|/* For use by the disassembler.  */
name|int
name|flags
decl_stmt|;
name|PTR
name|private_data
decl_stmt|;
comment|/* Function used to get bytes to disassemble.  MEMADDR is the      address of the stuff to be disassembled, MYADDR is the address to      put the bytes in, and LENGTH is the number of bytes to read.      INFO is a pointer to this struct.      Returns an errno value or 0 for success.  */
name|int
argument_list|(
argument|*read_memory_func
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
name|memaddr
operator|,
name|bfd_byte
operator|*
name|myaddr
operator|,
name|int
name|length
operator|,
expr|struct
name|disassemble_info
operator|*
name|info
operator|)
argument_list|)
expr_stmt|;
comment|/* Function which should be called if we get an error that we can't      recover from.  STATUS is the errno value from read_memory_func and      MEMADDR is the address that we were trying to read.  INFO is a      pointer to this struct.  */
name|void
argument_list|(
argument|*memory_error_func
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
name|status
operator|,
name|bfd_vma
name|memaddr
operator|,
expr|struct
name|disassemble_info
operator|*
name|info
operator|)
argument_list|)
expr_stmt|;
comment|/* Function called to print ADDR.  */
name|void
argument_list|(
argument|*print_address_func
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
name|addr
operator|,
expr|struct
name|disassemble_info
operator|*
name|info
operator|)
argument_list|)
expr_stmt|;
comment|/* These are for buffer_read_memory.  */
name|bfd_byte
modifier|*
name|buffer
decl_stmt|;
name|bfd_vma
name|buffer_vma
decl_stmt|;
name|int
name|buffer_length
decl_stmt|;
comment|/* Results from instruction decoders.  Not all decoders yet support      this information.  This info is set each time an instruction is      decoded, and is only valid for the last such instruction.       To determine whether this decoder supports this information, set      insn_info_valid to 0, decode an instruction, then check it.  */
name|char
name|insn_info_valid
decl_stmt|;
comment|/* Branch info has been set. */
name|char
name|branch_delay_insns
decl_stmt|;
comment|/* How many sequential insn's will run before 				   a branch takes effect.  (0 = normal) */
name|char
name|data_size
decl_stmt|;
comment|/* Size of data reference in insn, in bytes */
name|enum
name|dis_insn_type
name|insn_type
decl_stmt|;
comment|/* Type of instruction */
name|bfd_vma
name|target
decl_stmt|;
comment|/* Target address of branch or dref, if known; 				   zero if unknown.  */
name|bfd_vma
name|target2
decl_stmt|;
comment|/* Second target address for dref2 */
block|}
name|disassemble_info
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* Standard disassemblers.  Disassemble one instruction at the given    target address.  Return number of bytes processed.  */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*disassembler_ftype
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|print_insn_big_mips
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_little_mips
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_i386
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_m68k
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_z8001
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_z8002
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_h8300
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_h8300h
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_h8500
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_alpha
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_sparc
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_big_a29k
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_little_a29k
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_i960
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_sh
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_hppa
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_insn_m88k
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* This block of definitions is for particular callers who read instructions    into a buffer before calling the instruction decoder.  */
end_comment

begin_comment
comment|/* Here is a function which callers may wish to use for read_memory_func.    It gets bytes from a buffer.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|buffer_read_memory
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|bfd_byte
operator|*
operator|,
name|int
operator|,
expr|struct
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function goes with buffer_read_memory.    It prints a message using info->fprintf_func and info->stream.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|perror_memory
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|bfd_vma
operator|,
expr|struct
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Just print the address is hex.  This is included for completeness even    though both GDB and objdump provide their own (to print symbolic    addresses).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|generic_print_address
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
expr|struct
name|disassemble_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INIT_DISASSEMBLE_INFO
parameter_list|(
name|INFO
parameter_list|,
name|STREAM
parameter_list|)
define|\
value|(INFO).fprintf_func = (fprintf_ftype)fprintf, \   (INFO).stream = (STREAM), \   (INFO).buffer = NULL, \   (INFO).buffer_vma = 0, \   (INFO).buffer_length = 0, \   (INFO).read_memory_func = buffer_read_memory, \   (INFO).memory_error_func = perror_memory, \   (INFO).print_address_func = generic_print_address, \   (INFO).insn_info_valid = 0
end_define

begin_escape
end_escape

begin_comment
comment|/* This block of definitions is for calling the instruction decoders    from GDB.  */
end_comment

begin_comment
comment|/* GDB--Like target_read_memory, but slightly different parameters.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dis_asm_read_memory
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
name|memaddr
operator|,
name|bfd_byte
operator|*
name|myaddr
operator|,
name|int
name|len
operator|,
name|disassemble_info
operator|*
name|info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* GDB--Like memory_error with slightly different parameters.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dis_asm_memory_error
name|PARAMS
argument_list|(
operator|(
name|int
name|status
operator|,
name|bfd_vma
name|memaddr
operator|,
name|disassemble_info
operator|*
name|info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* GDB--Like print_address with slightly different parameters.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dis_asm_print_address
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
name|addr
operator|,
name|disassemble_info
operator|*
name|info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GDB_INIT_DISASSEMBLE_INFO
parameter_list|(
name|INFO
parameter_list|,
name|STREAM
parameter_list|)
define|\
value|(INFO).fprintf_func = (fprintf_ftype)fprintf_filtered, \   (INFO).stream = (STREAM), \   (INFO).read_memory_func = dis_asm_read_memory, \   (INFO).memory_error_func = dis_asm_memory_error, \   (INFO).print_address_func = dis_asm_print_address, \   (INFO).insn_info_valid = 0
end_define

end_unit

