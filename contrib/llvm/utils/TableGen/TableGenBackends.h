begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TableGenBackends.h - Declarations for LLVM TableGen Backends -------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file contains the declarations for all of the LLVM TableGen
end_comment

begin_comment
comment|// backends. A "TableGen backend" is just a function. See below for a
end_comment

begin_comment
comment|// precise description.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_UTILS_TABLEGEN_TABLEGENBACKENDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UTILS_TABLEGEN_TABLEGENBACKENDS_H
end_define

begin_comment
comment|// A TableGen backend is a function that looks like
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    EmitFoo(RecordKeeper&RK, raw_ostream&OS /*, anything else you need */ )
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// What you do inside of that function is up to you, but it will usually
end_comment

begin_comment
comment|// involve generating C++ code to the provided raw_ostream.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The RecordKeeper is just a top-level container for an in-memory
end_comment

begin_comment
comment|// representation of the data encoded in the TableGen file. What a TableGen
end_comment

begin_comment
comment|// backend does is walk around that in-memory representation and generate
end_comment

begin_comment
comment|// stuff based on the information it contains.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The in-memory representation is a node-graph (think of it like JSON but
end_comment

begin_comment
comment|// with a richer ontology of types), where the nodes are subclasses of
end_comment

begin_comment
comment|// Record. The methods `getClass`, `getDef` are the basic interface to
end_comment

begin_comment
comment|// access the node-graph.  RecordKeeper also provides a handy method
end_comment

begin_comment
comment|// `getAllDerivedDefinitions`. Consult "include/llvm/TableGen/Record.h" for
end_comment

begin_comment
comment|// the exact interfaces provided by Record's and RecordKeeper.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A common pattern for TableGen backends is for the EmitFoo function to
end_comment

begin_comment
comment|// instantiate a class which holds some context for the generation process,
end_comment

begin_comment
comment|// and then have most of the work happen in that class's methods. This
end_comment

begin_comment
comment|// pattern partly has historical roots in the previous TableGen backend API
end_comment

begin_comment
comment|// that involved a class and an invocation like `FooEmitter(RK).run(OS)`.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Remember to wrap private things in an anonymous namespace. For most
end_comment

begin_comment
comment|// backends, this means that the EmitFoo function is the only thing not in
end_comment

begin_comment
comment|// the anonymous namespace.
end_comment

begin_comment
comment|// FIXME: Reorganize TableGen so that build dependencies can be more
end_comment

begin_comment
comment|// accurately expressed. Currently, touching any of the emitters (or
end_comment

begin_comment
comment|// anything that they transitively depend on) causes everything dependent
end_comment

begin_comment
comment|// on TableGen to be rebuilt (this includes all the targets!). Perhaps have
end_comment

begin_comment
comment|// a standalone TableGen binary and have the backends be loadable modules
end_comment

begin_comment
comment|// of some sort; then the dependency could be expressed as being on the
end_comment

begin_comment
comment|// module, and all the modules would have a common dependency on the
end_comment

begin_comment
comment|// TableGen binary with as few dependencies as possible on the rest of
end_comment

begin_comment
comment|// LLVM.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|RecordKeeper
decl_stmt|;
name|void
name|EmitIntrinsics
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|bool
name|TargetOnly
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|EmitAsmMatcher
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitAsmWriter
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitCallingConv
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitCodeEmitter
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitDAGISel
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitDFAPacketizer
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitDisassembler
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitFastISel
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitInstrInfo
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitPseudoLowering
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitRegisterInfo
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitSubtarget
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitMapTable
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitOptParser
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitCTags
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitAttributes
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitSearchableTables
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitGlobalISel
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitX86EVEX2VEXTables
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|EmitRegisterBank
parameter_list|(
name|RecordKeeper
modifier|&
name|RK
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

