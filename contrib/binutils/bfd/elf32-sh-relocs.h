begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* No relocation.  */
end_comment

begin_expr_stmt
name|HOWTO
argument_list|(
name|R_SH_NONE
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_NONE"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* 32 bit absolute relocation.  Setting partial_inplace to TRUE and      src_mask to a non-zero value is similar to the COFF toolchain.  */
name|HOWTO
argument_list|(
name|R_SH_DIR32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|SH_ELF_RELOC
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR32"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* 32 bit PC relative relocation.  */
name|HOWTO
argument_list|(
name|R_SH_REL32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_REL32"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* 8 bit PC relative branch divided by 2.  */
name|HOWTO
argument_list|(
name|R_SH_DIR8WPN
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR8WPN"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xff
argument_list|,
comment|/* src_mask */
literal|0xff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* 12 bit PC relative branch divided by 2.  */
comment|/* This cannot be partial_inplace because relaxation can't know the      eventual value of a symbol.  */
name|HOWTO
argument_list|(
name|R_SH_IND12W
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|12
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|NULL
argument_list|,
comment|/* special_function */
literal|"R_SH_IND12W"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x0
argument_list|,
comment|/* src_mask */
literal|0xfff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* 8 bit unsigned PC relative divided by 4.  */
name|HOWTO
argument_list|(
name|R_SH_DIR8WPL
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR8WPL"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xff
argument_list|,
comment|/* src_mask */
literal|0xff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* 8 bit unsigned PC relative divided by 2.  */
name|HOWTO
argument_list|(
name|R_SH_DIR8WPZ
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR8WPZ"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xff
argument_list|,
comment|/* src_mask */
literal|0xff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* 8 bit GBR relative.  FIXME: This only makes sense if we have some      special symbol for the GBR relative area, and that is not      implemented.  */
name|HOWTO
argument_list|(
name|R_SH_DIR8BP
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR8BP"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* 8 bit GBR relative divided by 2.  FIXME: This only makes sense if      we have some special symbol for the GBR relative area, and that      is not implemented.  */
name|HOWTO
argument_list|(
name|R_SH_DIR8W
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR8W"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* 8 bit GBR relative divided by 4.  FIXME: This only makes sense if      we have some special symbol for the GBR relative area, and that      is not implemented.  */
name|HOWTO
argument_list|(
name|R_SH_DIR8L
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR8L"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* 8 bit PC relative divided by 2 - but specified in a very odd way.  */
name|HOWTO
argument_list|(
name|R_SH_LOOP_START
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_LOOP_START"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xff
argument_list|,
comment|/* src_mask */
literal|0xff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* 8 bit PC relative divided by 2 - but specified in a very odd way.  */
name|HOWTO
argument_list|(
name|R_SH_LOOP_END
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_LOOP_END"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xff
argument_list|,
comment|/* src_mask */
literal|0xff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|EMPTY_HOWTO
argument_list|(
literal|12
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|13
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|14
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|15
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|16
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|17
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|18
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|19
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|20
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|21
argument_list|)
operator|,
comment|/* The remaining relocs are a GNU extension used for relaxing.  The      final pass of the linker never needs to do anything with any of      these relocs.  Any required operations are handled by the      relaxation code.  */
comment|/* GNU extension to record C++ vtable hierarchy */
name|HOWTO
argument_list|(
name|R_SH_GNU_VTINHERIT
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|NULL
argument_list|,
comment|/* special_function */
literal|"R_SH_GNU_VTINHERIT"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* GNU extension to record C++ vtable member usage */
name|HOWTO
argument_list|(
name|R_SH_GNU_VTENTRY
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_elf_rel_vtable_reloc_fn
argument_list|,
comment|/* special_function */
literal|"R_SH_GNU_VTENTRY"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* An 8 bit switch table entry.  This is generated for an expression      such as ``.word L1 - L2''.  The offset holds the difference      between the reloc address and L2.  */
name|HOWTO
argument_list|(
name|R_SH_SWITCH8
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_SWITCH8"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* A 16 bit switch table entry.  This is generated for an expression      such as ``.word L1 - L2''.  The offset holds the difference      between the reloc address and L2.  */
name|HOWTO
argument_list|(
name|R_SH_SWITCH16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_SWITCH16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* A 32 bit switch table entry.  This is generated for an expression      such as ``.long L1 - L2''.  The offset holds the difference      between the reloc address and L2.  */
name|HOWTO
argument_list|(
name|R_SH_SWITCH32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_SWITCH32"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Indicates a .uses pseudo-op.  The compiler will generate .uses      pseudo-ops when it finds a function call which can be relaxed.      The offset field holds the PC relative offset to the instruction      which loads the register used in the function call.  */
name|HOWTO
argument_list|(
name|R_SH_USES
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_USES"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* The assembler will generate this reloc for addresses referred to      by the register loads associated with USES relocs.  The offset      field holds the number of times the address is referenced in the      object file.  */
name|HOWTO
argument_list|(
name|R_SH_COUNT
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_COUNT"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Indicates an alignment statement.  The offset field is the power      of 2 to which subsequent portions of the object file must be      aligned.  */
name|HOWTO
argument_list|(
name|R_SH_ALIGN
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_ALIGN"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* The assembler will generate this reloc before a block of      instructions.  A section should be processed as assuming it      contains data, unless this reloc is seen.  */
name|HOWTO
argument_list|(
name|R_SH_CODE
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_CODE"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* The assembler will generate this reloc after a block of      instructions when it sees data that is not instructions.  */
name|HOWTO
argument_list|(
name|R_SH_DATA
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DATA"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* The assembler generates this reloc for each label within a block      of instructions.  This permits the linker to avoid swapping      instructions which are the targets of branches.  */
name|HOWTO
argument_list|(
name|R_SH_LABEL
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_LABEL"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* The next 12 are only supported via linking in SHC-generated objects.  */
name|HOWTO
argument_list|(
name|R_SH_DIR16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_DIR8
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR8"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_DIR8UL
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR8UL"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_DIR8UW
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR8UW"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_DIR8U
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR8U"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_DIR8SW
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR8SW"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_DIR8S
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR8S"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_DIR4UL
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|4
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR4UL"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0f
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_DIR4UW
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|4
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR4UW"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0f
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_DIR4U
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|4
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR4U"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0f
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_PSHA
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|7
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|4
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_PSHA"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0f
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_PSHL
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|7
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|4
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_PSHL"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0f
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
ifdef|#
directive|ifdef
name|INCLUDE_SHMEDIA
comment|/* Used in SHLLI.L and SHLRI.L.  */
name|HOWTO
argument_list|(
name|R_SH_DIR5U
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|5
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR5U"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xfc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in SHARI, SHLLI et al.  */
name|HOWTO
argument_list|(
name|R_SH_DIR6U
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|6
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR6U"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xfc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in BxxI, LDHI.L et al.  */
name|HOWTO
argument_list|(
name|R_SH_DIR6S
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|6
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR6S"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xfc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in ADDI, ANDI et al.  */
name|HOWTO
argument_list|(
name|R_SH_DIR10S
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|10
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR10S"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in LD.UW, ST.W et al.	 */
name|HOWTO
argument_list|(
name|R_SH_DIR10SW
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|11
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR10SW"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in LD.L, FLD.S et al.	 */
name|HOWTO
argument_list|(
name|R_SH_DIR10SL
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|12
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR10SL"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in FLD.D, FST.P et al.  */
name|HOWTO
argument_list|(
name|R_SH_DIR10SQ
argument_list|,
comment|/* type */
literal|3
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|13
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR10SQ"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
else|#
directive|else
name|EMPTY_HOWTO
argument_list|(
literal|45
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|46
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|47
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|48
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|49
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|50
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|51
argument_list|)
operator|,
endif|#
directive|endif
name|EMPTY_HOWTO
argument_list|(
literal|52
argument_list|)
operator|,
name|HOWTO
argument_list|(
name|R_SH_DIR16S
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_DIR16S"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|EMPTY_HOWTO
argument_list|(
literal|54
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|55
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|56
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|57
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|58
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|59
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|60
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|61
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|62
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|63
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|64
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|65
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|66
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|67
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|68
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|69
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|70
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|71
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|72
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|73
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|74
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|75
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|76
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|77
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|78
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|79
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|80
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|81
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|82
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|83
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|84
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|85
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|86
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|87
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|88
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|89
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|90
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|91
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|92
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|93
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|94
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|95
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|96
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|97
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|98
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|99
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|100
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|101
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|102
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|103
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|104
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|105
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|106
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|107
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|108
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|109
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|110
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|111
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|112
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|113
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|114
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|115
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|116
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|117
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|118
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|119
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|120
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|121
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|122
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|123
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|124
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|125
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|126
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|127
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|128
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|129
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|130
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|131
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|132
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|133
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|134
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|135
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|136
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|137
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|138
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|139
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|140
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|141
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|142
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|143
argument_list|)
operator|,
name|HOWTO
argument_list|(
name|R_SH_TLS_GD_32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_TLS_GD_32"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_TLS_LD_32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_TLS_LD_32"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_TLS_LDO_32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_TLS_LDO_32"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_TLS_IE_32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_TLS_IE_32"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_TLS_LE_32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_TLS_LE_32"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_TLS_DTPMOD32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_TLS_DTPMOD32"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_TLS_DTPOFF32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_TLS_DTPOFF32"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_TLS_TPOFF32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_TLS_TPOFF32"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|EMPTY_HOWTO
argument_list|(
literal|152
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|153
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|154
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|155
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|156
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|157
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|158
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|159
argument_list|)
operator|,
name|HOWTO
argument_list|(
name|R_SH_GOT32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_GOT32"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_PLT32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_PLT32"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_COPY
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_COPY"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_GLOB_DAT
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_GLOB_DAT"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_JMP_SLOT
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_JMP_SLOT"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_RELATIVE
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_RELATIVE"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_GOTOFF
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_GOTOFF"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_GOTPC
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_GOTPC"
argument_list|,
comment|/* name */
name|SH_PARTIAL32
argument_list|,
comment|/* partial_inplace */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_GOTPLT32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* */
literal|"R_SH_GOTPLT32"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
comment|/* ??? Why not 0?  */
name|SH_SRC_MASK32
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
ifdef|#
directive|ifdef
name|INCLUDE_SHMEDIA
comment|/* Used in MOVI and SHORI (x& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOT_LOW16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOT_LOW16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 16)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOT_MEDLOW16
argument_list|,
comment|/* type */
literal|16
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOT_MEDLOW16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 32)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOT_MEDHI16
argument_list|,
comment|/* type */
literal|32
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOT_MEDHI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 48)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOT_HI16
argument_list|,
comment|/* type */
literal|48
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOT_HI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI (x& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOTPLT_LOW16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOTPLT_LOW16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 16)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOTPLT_MEDLOW16
argument_list|,
comment|/* type */
literal|16
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOTPLT_MEDLOW16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 32)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOTPLT_MEDHI16
argument_list|,
comment|/* type */
literal|32
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOTPLT_MEDHI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 48)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOTPLT_HI16
argument_list|,
comment|/* type */
literal|48
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOTPLT_HI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI (x& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_PLT_LOW16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_PLT_LOW16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 16)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_PLT_MEDLOW16
argument_list|,
comment|/* type */
literal|16
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_PLT_MEDLOW16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 32)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_PLT_MEDHI16
argument_list|,
comment|/* type */
literal|32
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_PLT_MEDHI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 48)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_PLT_HI16
argument_list|,
comment|/* type */
literal|48
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_PLT_HI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI (x& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOTOFF_LOW16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOTOFF_LOW16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 16)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOTOFF_MEDLOW16
argument_list|,
comment|/* type */
literal|16
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOTOFF_MEDLOW16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 32)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOTOFF_MEDHI16
argument_list|,
comment|/* type */
literal|32
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOTOFF_MEDHI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 48)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOTOFF_HI16
argument_list|,
comment|/* type */
literal|48
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOTOFF_HI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI (x& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOTPC_LOW16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOTPC_LOW16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 16)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOTPC_MEDLOW16
argument_list|,
comment|/* type */
literal|16
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOTPC_MEDLOW16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 32)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOTPC_MEDHI16
argument_list|,
comment|/* type */
literal|32
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOTPC_MEDHI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 48)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_GOTPC_HI16
argument_list|,
comment|/* type */
literal|48
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOTPC_HI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in LD.L, FLD.S et al.	 */
name|HOWTO
argument_list|(
name|R_SH_GOT10BY4
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|12
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOT10BY4"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in LD.L, FLD.S et al.	 */
name|HOWTO
argument_list|(
name|R_SH_GOTPLT10BY4
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|12
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOTPLT10BY4"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in FLD.D, FST.P et al.  */
name|HOWTO
argument_list|(
name|R_SH_GOT10BY8
argument_list|,
comment|/* type */
literal|3
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|13
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOT10BY8"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in FLD.D, FST.P et al.  */
name|HOWTO
argument_list|(
name|R_SH_GOTPLT10BY8
argument_list|,
comment|/* type */
literal|3
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|13
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GOTPLT10BY8"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_COPY64
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|4
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_COPY64"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
operator|(
operator|(
name|bfd_vma
operator|)
literal|0
operator|)
operator|-
literal|1
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_GLOB_DAT64
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|4
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_GLOB_DAT64"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
operator|(
operator|(
name|bfd_vma
operator|)
literal|0
operator|)
operator|-
literal|1
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_JMP_SLOT64
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|4
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_JMP_SLOT64"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
operator|(
operator|(
name|bfd_vma
operator|)
literal|0
operator|)
operator|-
literal|1
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_SH_RELATIVE64
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|4
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_RELATIVE64"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
operator|(
operator|(
name|bfd_vma
operator|)
literal|0
operator|)
operator|-
literal|1
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
name|EMPTY_HOWTO
argument_list|(
literal|197
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|198
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|199
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|200
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|201
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|202
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|203
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|204
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|205
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|206
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|207
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|208
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|209
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|210
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|211
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|212
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|213
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|214
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|215
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|216
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|217
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|218
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|219
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|220
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|221
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|222
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|223
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|224
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|225
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|226
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|227
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|228
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|229
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|230
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|231
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|232
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|233
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|234
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|235
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|236
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|237
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|238
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|239
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|240
argument_list|)
operator|,
name|EMPTY_HOWTO
argument_list|(
literal|241
argument_list|)
operator|,
comment|/* Relocations for SHmedia code.  None of these are partial_inplace or      use the field being relocated (except R_SH_PT_16).  */
comment|/* The assembler will generate this reloc before a block of SHmedia      instructions.  A section should be processed as assuming it contains      data, unless this reloc is seen.  Note that a block of SHcompact      instructions are instead preceded by R_SH_CODE.      This is currently not implemented, but should be used for SHmedia      linker relaxation.  */
name|HOWTO
argument_list|(
name|R_SH_SHMEDIA_CODE
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|sh_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_SHMEDIA_CODE"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* The assembler will generate this reloc at a PTA or PTB instruction,      and the linker checks the right type of target, or changes a PTA to a      PTB, if the original insn was PT.  */
name|HOWTO
argument_list|(
name|R_SH_PT_16
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|18
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_PT_16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in unexpanded MOVI.  */
name|HOWTO
argument_list|(
name|R_SH_IMMS16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_IMMS16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in SHORI.  */
name|HOWTO
argument_list|(
name|R_SH_IMMU16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_IMMU16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI (x& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_IMM_LOW16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_IMM_LOW16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x - $)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_IMM_LOW16_PCREL
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_IMM_LOW16_PCREL"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 16)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_IMM_MEDLOW16
argument_list|,
comment|/* type */
literal|16
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_IMM_MEDLOW16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI (((x - $)>> 16)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_IMM_MEDLOW16_PCREL
argument_list|,
comment|/* type */
literal|16
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_IMM_MEDLOW16_PCREL"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 32)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_IMM_MEDHI16
argument_list|,
comment|/* type */
literal|32
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_IMM_MEDHI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI (((x - $)>> 32)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_IMM_MEDHI16_PCREL
argument_list|,
comment|/* type */
literal|32
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_IMM_MEDHI16_PCREL"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI ((x>> 48)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_IMM_HI16
argument_list|,
comment|/* type */
literal|48
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_IMM_HI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* Used in MOVI and SHORI (((x - $)>> 48)& 65536).  */
name|HOWTO
argument_list|(
name|R_SH_IMM_HI16_PCREL
argument_list|,
comment|/* type */
literal|48
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_IMM_HI16_PCREL"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffc00
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* For the .uaquad pseudo.  */
name|HOWTO
argument_list|(
name|R_SH_64
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|4
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_64"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
operator|(
operator|(
name|bfd_vma
operator|)
literal|0
operator|)
operator|-
literal|1
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
operator|,
comment|/* pcrel_offset */
comment|/* For the .uaquad pseudo, (x - $).  */
name|HOWTO
argument_list|(
name|R_SH_64_PCREL
argument_list|,
comment|/* type */
literal|48
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|10
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_SH_64_PCREL"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
operator|(
operator|(
name|bfd_vma
operator|)
literal|0
operator|)
operator|-
literal|1
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
operator|,
end_expr_stmt

begin_comment
comment|/* pcrel_offset */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|SH_PARTIAL32
end_undef

begin_undef
undef|#
directive|undef
name|SH_SRC_MASK32
end_undef

begin_undef
undef|#
directive|undef
name|SH_ELF_RELOC
end_undef

end_unit

