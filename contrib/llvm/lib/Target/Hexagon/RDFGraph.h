begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- RDFGraph.h ---------------------------------------------*- C++ -*-===//
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
comment|// Target-independent, SSA-based data flow graph for register data flow (RDF)
end_comment

begin_comment
comment|// for a non-SSA program representation (e.g. post-RA machine code).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// *** Introduction
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The RDF graph is a collection of nodes, each of which denotes some element
end_comment

begin_comment
comment|// of the program. There are two main types of such elements: code and refe-
end_comment

begin_comment
comment|// rences. Conceptually, "code" is something that represents the structure
end_comment

begin_comment
comment|// of the program, e.g. basic block or a statement, while "reference" is an
end_comment

begin_comment
comment|// instance of accessing a register, e.g. a definition or a use. Nodes are
end_comment

begin_comment
comment|// connected with each other based on the structure of the program (such as
end_comment

begin_comment
comment|// blocks, instructions, etc.), and based on the data flow (e.g. reaching
end_comment

begin_comment
comment|// definitions, reached uses, etc.). The single-reaching-definition principle
end_comment

begin_comment
comment|// of SSA is generally observed, although, due to the non-SSA representation
end_comment

begin_comment
comment|// of the program, there are some differences between the graph and a "pure"
end_comment

begin_comment
comment|// SSA representation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// *** Implementation remarks
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Since the graph can contain a large number of nodes, memory consumption
end_comment

begin_comment
comment|// was one of the major design considerations. As a result, there is a single
end_comment

begin_comment
comment|// base class NodeBase which defines all members used by all possible derived
end_comment

begin_comment
comment|// classes. The members are arranged in a union, and a derived class cannot
end_comment

begin_comment
comment|// add any data members of its own. Each derived class only defines the
end_comment

begin_comment
comment|// functional interface, i.e. member functions. NodeBase must be a POD,
end_comment

begin_comment
comment|// which implies that all of its members must also be PODs.
end_comment

begin_comment
comment|// Since nodes need to be connected with other nodes, pointers have been
end_comment

begin_comment
comment|// replaced with 32-bit identifiers: each node has an id of type NodeId.
end_comment

begin_comment
comment|// There are mapping functions in the graph that translate between actual
end_comment

begin_comment
comment|// memory addresses and the corresponding identifiers.
end_comment

begin_comment
comment|// A node id of 0 is equivalent to nullptr.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// *** Structure of the graph
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A code node is always a collection of other nodes. For example, a code
end_comment

begin_comment
comment|// node corresponding to a basic block will contain code nodes corresponding
end_comment

begin_comment
comment|// to instructions. In turn, a code node corresponding to an instruction will
end_comment

begin_comment
comment|// contain a list of reference nodes that correspond to the definitions and
end_comment

begin_comment
comment|// uses of registers in that instruction. The members are arranged into a
end_comment

begin_comment
comment|// circular list, which is yet another consequence of the effort to save
end_comment

begin_comment
comment|// memory: for each member node it should be possible to obtain its owner,
end_comment

begin_comment
comment|// and it should be possible to access all other members. There are other
end_comment

begin_comment
comment|// ways to accomplish that, but the circular list seemed the most natural.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// +- CodeNode -+
end_comment

begin_comment
comment|// |            |<---------------------------------------------------+
end_comment

begin_comment
comment|// +-+--------+-+                                                     |
end_comment

begin_comment
comment|//   |FirstM  |LastM                                                  |
end_comment

begin_comment
comment|//   |        +-------------------------------------+                 |
end_comment

begin_comment
comment|//   |                                              |                 |
end_comment

begin_comment
comment|//   V                                              V                 |
end_comment

begin_comment
comment|//  +----------+ Next +----------+ Next       Next +----------+ Next  |
end_comment

begin_comment
comment|//  |          |----->|          |-----> ... ----->|          |----->-+
end_comment

begin_comment
comment|//  +- Member -+      +- Member -+                 +- Member -+
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The order of members is such that related reference nodes (see below)
end_comment

begin_comment
comment|// should be contiguous on the member list.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A reference node is a node that encapsulates an access to a register,
end_comment

begin_comment
comment|// in other words, data flowing into or out of a register. There are two
end_comment

begin_comment
comment|// major kinds of reference nodes: defs and uses. A def node will contain
end_comment

begin_comment
comment|// the id of the first reached use, and the id of the first reached def.
end_comment

begin_comment
comment|// Each def and use will contain the id of the reaching def, and also the
end_comment

begin_comment
comment|// id of the next reached def (for def nodes) or use (for use nodes).
end_comment

begin_comment
comment|// The "next node sharing the same reaching def" is denoted as "sibling".
end_comment

begin_comment
comment|// In summary:
end_comment

begin_comment
comment|// - Def node contains: reaching def, sibling, first reached def, and first
end_comment

begin_comment
comment|// reached use.
end_comment

begin_comment
comment|// - Use node contains: reaching def and sibling.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// +-- DefNode --+
end_comment

begin_comment
comment|// | R2 = ...    |<---+--------------------+
end_comment

begin_comment
comment|// ++---------+--+     |                    |
end_comment

begin_comment
comment|//  |Reached  |Reached |                    |
end_comment

begin_comment
comment|//  |Def      |Use     |                    |
end_comment

begin_comment
comment|//  |         |        |Reaching            |Reaching
end_comment

begin_comment
comment|//  |         V        |Def                 |Def
end_comment

begin_comment
comment|//  |      +-- UseNode --+ Sib  +-- UseNode --+ Sib       Sib
end_comment

begin_comment
comment|//  |      | ... = R2    |----->| ... = R2    |----> ... ----> 0
end_comment

begin_comment
comment|//  |      +-------------+      +-------------+
end_comment

begin_comment
comment|//  V
end_comment

begin_comment
comment|// +-- DefNode --+ Sib
end_comment

begin_comment
comment|// | R2 = ...    |----> ...
end_comment

begin_comment
comment|// ++---------+--+
end_comment

begin_comment
comment|//  |         |
end_comment

begin_comment
comment|//  |         |
end_comment

begin_comment
comment|// ...       ...
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To get a full picture, the circular lists connecting blocks within a
end_comment

begin_comment
comment|// function, instructions within a block, etc. should be superimposed with
end_comment

begin_comment
comment|// the def-def, def-use links shown above.
end_comment

begin_comment
comment|// To illustrate this, consider a small example in a pseudo-assembly:
end_comment

begin_comment
comment|// foo:
end_comment

begin_comment
comment|//   add r2, r0, r1   ; r2 = r0+r1
end_comment

begin_comment
comment|//   addi r0, r2, 1   ; r0 = r2+1
end_comment

begin_comment
comment|//   ret r0           ; return value in r0
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The graph (in a format used by the debugging functions) would look like:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   DFG dump:[
end_comment

begin_comment
comment|//   f1: Function foo
end_comment

begin_comment
comment|//   b2: === BB#0 === preds(0), succs(0):
end_comment

begin_comment
comment|//   p3: phi [d4<r0>(,d12,u9):]
end_comment

begin_comment
comment|//   p5: phi [d6<r1>(,,u10):]
end_comment

begin_comment
comment|//   s7: add [d8<r2>(,,u13):, u9<r0>(d4):, u10<r1>(d6):]
end_comment

begin_comment
comment|//   s11: addi [d12<r0>(d4,,u15):, u13<r2>(d8):]
end_comment

begin_comment
comment|//   s14: ret [u15<r0>(d12):]
end_comment

begin_comment
comment|//   ]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The f1, b2, p3, etc. are node ids. The letter is prepended to indicate the
end_comment

begin_comment
comment|// kind of the node (i.e. f - function, b - basic block, p - phi, s - state-
end_comment

begin_comment
comment|// ment, d - def, u - use).
end_comment

begin_comment
comment|// The format of a def node is:
end_comment

begin_comment
comment|//   dN<R>(rd,d,u):sib,
end_comment

begin_comment
comment|// where
end_comment

begin_comment
comment|//   N   - numeric node id,
end_comment

begin_comment
comment|//   R   - register being defined
end_comment

begin_comment
comment|//   rd  - reaching def,
end_comment

begin_comment
comment|//   d   - reached def,
end_comment

begin_comment
comment|//   u   - reached use,
end_comment

begin_comment
comment|//   sib - sibling.
end_comment

begin_comment
comment|// The format of a use node is:
end_comment

begin_comment
comment|//   uN<R>[!](rd):sib,
end_comment

begin_comment
comment|// where
end_comment

begin_comment
comment|//   N   - numeric node id,
end_comment

begin_comment
comment|//   R   - register being used,
end_comment

begin_comment
comment|//   rd  - reaching def,
end_comment

begin_comment
comment|//   sib - sibling.
end_comment

begin_comment
comment|// Possible annotations (usually preceding the node id):
end_comment

begin_comment
comment|//   +   - preserving def,
end_comment

begin_comment
comment|//   ~   - clobbering def,
end_comment

begin_comment
comment|//   "   - shadow ref (follows the node id),
end_comment

begin_comment
comment|//   !   - fixed register (appears after register name).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The circular lists are not explicit in the dump.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// *** Node attributes
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NodeBase has a member "Attrs", which is the primary way of determining
end_comment

begin_comment
comment|// the node's characteristics. The fields in this member decide whether
end_comment

begin_comment
comment|// the node is a code node or a reference node (i.e. node's "type"), then
end_comment

begin_comment
comment|// within each type, the "kind" determines what specifically this node
end_comment

begin_comment
comment|// represents. The remaining bits, "flags", contain additional information
end_comment

begin_comment
comment|// that is even more detailed than the "kind".
end_comment

begin_comment
comment|// CodeNode's kinds are:
end_comment

begin_comment
comment|// - Phi:   Phi node, members are reference nodes.
end_comment

begin_comment
comment|// - Stmt:  Statement, members are reference nodes.
end_comment

begin_comment
comment|// - Block: Basic block, members are instruction nodes (i.e. Phi or Stmt).
end_comment

begin_comment
comment|// - Func:  The whole function. The members are basic block nodes.
end_comment

begin_comment
comment|// RefNode's kinds are:
end_comment

begin_comment
comment|// - Use.
end_comment

begin_comment
comment|// - Def.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Meaning of flags:
end_comment

begin_comment
comment|// - Preserving: applies only to defs. A preserving def is one that can
end_comment

begin_comment
comment|//   preserve some of the original bits among those that are included in
end_comment

begin_comment
comment|//   the register associated with that def. For example, if R0 is a 32-bit
end_comment

begin_comment
comment|//   register, but a def can only change the lower 16 bits, then it will
end_comment

begin_comment
comment|//   be marked as preserving.
end_comment

begin_comment
comment|// - Shadow: a reference that has duplicates holding additional reaching
end_comment

begin_comment
comment|//   defs (see more below).
end_comment

begin_comment
comment|// - Clobbering: applied only to defs, indicates that the value generated
end_comment

begin_comment
comment|//   by this def is unspecified. A typical example would be volatile registers
end_comment

begin_comment
comment|//   after function calls.
end_comment

begin_comment
comment|// - Fixed: the register in this def/use cannot be replaced with any other
end_comment

begin_comment
comment|//   register. A typical case would be a parameter register to a call, or
end_comment

begin_comment
comment|//   the register with the return value from a function.
end_comment

begin_comment
comment|// - Undef: the register in this reference the register is assumed to have
end_comment

begin_comment
comment|//   no pre-existing value, even if it appears to be reached by some def.
end_comment

begin_comment
comment|//   This is typically used to prevent keeping registers artificially live
end_comment

begin_comment
comment|//   in cases when they are defined via predicated instructions. For example:
end_comment

begin_comment
comment|//     r0 = add-if-true cond, r10, r11                (1)
end_comment

begin_comment
comment|//     r0 = add-if-false cond, r12, r13, r0<imp-use>  (2)
end_comment

begin_comment
comment|//     ... = r0                                       (3)
end_comment

begin_comment
comment|//   Before (1), r0 is not intended to be live, and the use of r0 in (3) is
end_comment

begin_comment
comment|//   not meant to be reached by any def preceding (1). However, since the
end_comment

begin_comment
comment|//   defs in (1) and (2) are both preserving, these properties alone would
end_comment

begin_comment
comment|//   imply that the use in (3) may indeed be reached by some prior def.
end_comment

begin_comment
comment|//   Adding Undef flag to the def in (1) prevents that. The Undef flag
end_comment

begin_comment
comment|//   may be applied to both defs and uses.
end_comment

begin_comment
comment|// - Dead: applies only to defs. The value coming out of a "dead" def is
end_comment

begin_comment
comment|//   assumed to be unused, even if the def appears to be reaching other defs
end_comment

begin_comment
comment|//   or uses. The motivation for this flag comes from dead defs on function
end_comment

begin_comment
comment|//   calls: there is no way to determine if such a def is dead without
end_comment

begin_comment
comment|//   analyzing the target's ABI. Hence the graph should contain this info,
end_comment

begin_comment
comment|//   as it is unavailable otherwise. On the other hand, a def without any
end_comment

begin_comment
comment|//   uses on a typical instruction is not the intended target for this flag.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// *** Shadow references
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// It may happen that a super-register can have two (or more) non-overlapping
end_comment

begin_comment
comment|// sub-registers. When both of these sub-registers are defined and followed
end_comment

begin_comment
comment|// by a use of the super-register, the use of the super-register will not
end_comment

begin_comment
comment|// have a unique reaching def: both defs of the sub-registers need to be
end_comment

begin_comment
comment|// accounted for. In such cases, a duplicate use of the super-register is
end_comment

begin_comment
comment|// added and it points to the extra reaching def. Both uses are marked with
end_comment

begin_comment
comment|// a flag "shadow". Example:
end_comment

begin_comment
comment|// Assume t0 is a super-register of r0 and r1, r0 and r1 do not overlap:
end_comment

begin_comment
comment|//   set r0, 1        ; r0 = 1
end_comment

begin_comment
comment|//   set r1, 1        ; r1 = 1
end_comment

begin_comment
comment|//   addi t1, t0, 1   ; t1 = t0+1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The DFG:
end_comment

begin_comment
comment|//   s1: set [d2<r0>(,,u9):]
end_comment

begin_comment
comment|//   s3: set [d4<r1>(,,u10):]
end_comment

begin_comment
comment|//   s5: addi [d6<t1>(,,):, u7"<t0>(d2):, u8"<t0>(d4):]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The statement s5 has two use nodes for t0: u7" and u9". The quotation
end_comment

begin_comment
comment|// mark " indicates that the node is a shadow.
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_HEXAGON_RDFGRAPH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_RDFGRAPH_H
end_define

begin_include
include|#
directive|include
file|"RDFRegisters.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/LaneBitmask.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// RDF uses uint32_t to refer to registers. This is to ensure that the type
end_comment

begin_comment
comment|// size remains specific. In other places, registers are often stored using
end_comment

begin_comment
comment|// unsigned.
end_comment

begin_expr_stmt
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
argument_list|,
literal|"Those should be equal"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineOperand
decl_stmt|;
name|class
name|MachineDominanceFrontier
decl_stmt|;
name|class
name|MachineDominatorTree
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|namespace
name|rdf
block|{
typedef|typedef
name|uint32_t
name|NodeId
typedef|;
struct_decl|struct
name|DataFlowGraph
struct_decl|;
struct|struct
name|NodeAttrs
block|{
enum_decl|enum :
name|uint16_t
block|{
name|None
init|=
literal|0x0000
block|,
comment|// Nothing
comment|// Types: 2 bits
name|TypeMask
init|=
literal|0x0003
block|,
name|Code
init|=
literal|0x0001
block|,
comment|// 01, Container
name|Ref
init|=
literal|0x0002
block|,
comment|// 10, Reference
comment|// Kind: 3 bits
name|KindMask
init|=
literal|0x0007
operator|<<
literal|2
block|,
name|Def
init|=
literal|0x0001
operator|<<
literal|2
block|,
comment|// 001
name|Use
init|=
literal|0x0002
operator|<<
literal|2
block|,
comment|// 010
name|Phi
init|=
literal|0x0003
operator|<<
literal|2
block|,
comment|// 011
name|Stmt
init|=
literal|0x0004
operator|<<
literal|2
block|,
comment|// 100
name|Block
init|=
literal|0x0005
operator|<<
literal|2
block|,
comment|// 101
name|Func
init|=
literal|0x0006
operator|<<
literal|2
block|,
comment|// 110
comment|// Flags: 7 bits for now
name|FlagMask
init|=
literal|0x007F
operator|<<
literal|5
block|,
name|Shadow
init|=
literal|0x0001
operator|<<
literal|5
block|,
comment|// 0000001, Has extra reaching defs.
name|Clobbering
init|=
literal|0x0002
operator|<<
literal|5
block|,
comment|// 0000010, Produces unspecified values.
name|PhiRef
init|=
literal|0x0004
operator|<<
literal|5
block|,
comment|// 0000100, Member of PhiNode.
name|Preserving
init|=
literal|0x0008
operator|<<
literal|5
block|,
comment|// 0001000, Def can keep original bits.
name|Fixed
init|=
literal|0x0010
operator|<<
literal|5
block|,
comment|// 0010000, Fixed register.
name|Undef
init|=
literal|0x0020
operator|<<
literal|5
block|,
comment|// 0100000, Has no pre-existing value.
name|Dead
init|=
literal|0x0040
operator|<<
literal|5
block|,
comment|// 1000000, Does not define a value.
block|}
enum_decl|;
specifier|static
name|uint16_t
name|type
parameter_list|(
name|uint16_t
name|T
parameter_list|)
block|{
return|return
name|T
operator|&
name|TypeMask
return|;
block|}
specifier|static
name|uint16_t
name|kind
parameter_list|(
name|uint16_t
name|T
parameter_list|)
block|{
return|return
name|T
operator|&
name|KindMask
return|;
block|}
specifier|static
name|uint16_t
name|flags
parameter_list|(
name|uint16_t
name|T
parameter_list|)
block|{
return|return
name|T
operator|&
name|FlagMask
return|;
block|}
specifier|static
name|uint16_t
name|set_type
parameter_list|(
name|uint16_t
name|A
parameter_list|,
name|uint16_t
name|T
parameter_list|)
block|{
return|return
operator|(
name|A
operator|&
operator|~
name|TypeMask
operator|)
operator||
name|T
return|;
block|}
specifier|static
name|uint16_t
name|set_kind
parameter_list|(
name|uint16_t
name|A
parameter_list|,
name|uint16_t
name|K
parameter_list|)
block|{
return|return
operator|(
name|A
operator|&
operator|~
name|KindMask
operator|)
operator||
name|K
return|;
block|}
specifier|static
name|uint16_t
name|set_flags
parameter_list|(
name|uint16_t
name|A
parameter_list|,
name|uint16_t
name|F
parameter_list|)
block|{
return|return
operator|(
name|A
operator|&
operator|~
name|FlagMask
operator|)
operator||
name|F
return|;
block|}
comment|// Test if A contains B.
specifier|static
name|bool
name|contains
parameter_list|(
name|uint16_t
name|A
parameter_list|,
name|uint16_t
name|B
parameter_list|)
block|{
if|if
condition|(
name|type
argument_list|(
name|A
argument_list|)
operator|!=
name|Code
condition|)
return|return
name|false
return|;
name|uint16_t
name|KB
init|=
name|kind
argument_list|(
name|B
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|kind
argument_list|(
name|A
argument_list|)
condition|)
block|{
case|case
name|Func
case|:
return|return
name|KB
operator|==
name|Block
return|;
case|case
name|Block
case|:
return|return
name|KB
operator|==
name|Phi
operator|||
name|KB
operator|==
name|Stmt
return|;
case|case
name|Phi
case|:
case|case
name|Stmt
case|:
return|return
name|type
argument_list|(
name|B
argument_list|)
operator|==
name|Ref
return|;
block|}
return|return
name|false
return|;
block|}
block|}
struct|;
struct|struct
name|BuildOptions
block|{
enum_decl|enum :
name|unsigned
block|{
name|None
init|=
literal|0x00
block|,
name|KeepDeadPhis
init|=
literal|0x01
block|,
comment|// Do not remove dead phis during build.
block|}
enum_decl|;
block|}
struct|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|NodeAddr
block|{
name|NodeAddr
argument_list|()
operator|:
name|Addr
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|NodeAddr
argument_list|(
argument|T A
argument_list|,
argument|NodeId I
argument_list|)
operator|:
name|Addr
argument_list|(
name|A
argument_list|)
block|,
name|Id
argument_list|(
argument|I
argument_list|)
block|{}
comment|// Type cast (casting constructor). The reason for having this class
comment|// instead of std::pair.
name|template
operator|<
name|typename
name|S
operator|>
name|NodeAddr
argument_list|(
specifier|const
name|NodeAddr
operator|<
name|S
operator|>
operator|&
name|NA
argument_list|)
operator|:
name|Addr
argument_list|(
name|static_cast
operator|<
name|T
operator|>
operator|(
name|NA
operator|.
name|Addr
operator|)
argument_list|)
block|,
name|Id
argument_list|(
argument|NA.Id
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|NodeAddr
operator|<
name|T
operator|>
operator|&
name|NA
operator|)
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Addr
operator|==
name|NA
operator|.
name|Addr
operator|)
operator|==
operator|(
name|Id
operator|==
name|NA
operator|.
name|Id
operator|)
argument_list|)
block|;
return|return
name|Addr
operator|==
name|NA
operator|.
name|Addr
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|NodeAddr
operator|<
name|T
operator|>
operator|&
name|NA
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|NA
operator|)
return|;
block|}
name|T
name|Addr
block|;
name|NodeId
name|Id
operator|=
literal|0
block|;   }
expr_stmt|;
struct_decl|struct
name|NodeBase
struct_decl|;
comment|// Fast memory allocation and translation between node id and node address.
comment|// This is really the same idea as the one underlying the "bump pointer
comment|// allocator", the difference being in the translation. A node id is
comment|// composed of two components: the index of the block in which it was
comment|// allocated, and the index within the block. With the default settings,
comment|// where the number of nodes per block is 4096, the node id (minus 1) is:
comment|//
comment|// bit position:                11             0
comment|// +----------------------------+--------------+
comment|// | Index of the block         |Index in block|
comment|// +----------------------------+--------------+
comment|//
comment|// The actual node id is the above plus 1, to avoid creating a node id of 0.
comment|//
comment|// This method significantly improved the build time, compared to using maps
comment|// (std::unordered_map or DenseMap) to translate between pointers and ids.
struct|struct
name|NodeAllocator
block|{
comment|// Amount of storage for a single node.
enum|enum
block|{
name|NodeMemSize
init|=
literal|32
block|}
enum|;
name|NodeAllocator
argument_list|(
argument|uint32_t NPB =
literal|4096
argument_list|)
block|:
name|NodesPerBlock
argument_list|(
name|NPB
argument_list|)
operator|,
name|BitsPerIndex
argument_list|(
name|Log2_32
argument_list|(
name|NPB
argument_list|)
argument_list|)
operator|,
name|IndexMask
argument_list|(
argument|(
literal|1
argument|<< BitsPerIndex)-
literal|1
argument_list|)
block|{
name|assert
argument_list|(
name|isPowerOf2_32
argument_list|(
name|NPB
argument_list|)
argument_list|)
block|;     }
name|NodeBase
operator|*
name|ptr
argument_list|(
argument|NodeId N
argument_list|)
specifier|const
block|{
name|uint32_t
name|N1
operator|=
name|N
operator|-
literal|1
block|;
name|uint32_t
name|BlockN
operator|=
name|N1
operator|>>
name|BitsPerIndex
block|;
name|uint32_t
name|Offset
operator|=
operator|(
name|N1
operator|&
name|IndexMask
operator|)
operator|*
name|NodeMemSize
block|;
return|return
name|reinterpret_cast
operator|<
name|NodeBase
operator|*
operator|>
operator|(
name|Blocks
index|[
name|BlockN
index|]
operator|+
name|Offset
operator|)
return|;
block|}
name|NodeId
name|id
argument_list|(
specifier|const
name|NodeBase
operator|*
name|P
argument_list|)
decl|const
decl_stmt|;
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|New
argument_list|()
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|startNewBlock
parameter_list|()
function_decl|;
name|bool
name|needNewBlock
parameter_list|()
function_decl|;
name|uint32_t
name|makeId
argument_list|(
name|uint32_t
name|Block
argument_list|,
name|uint32_t
name|Index
argument_list|)
decl|const
block|{
comment|// Add 1 to the id, to avoid the id of 0, which is treated as "null".
return|return
operator|(
operator|(
name|Block
operator|<<
name|BitsPerIndex
operator|)
operator||
name|Index
operator|)
operator|+
literal|1
return|;
block|}
specifier|const
name|uint32_t
name|NodesPerBlock
decl_stmt|;
specifier|const
name|uint32_t
name|BitsPerIndex
decl_stmt|;
specifier|const
name|uint32_t
name|IndexMask
decl_stmt|;
name|char
modifier|*
name|ActiveEnd
init|=
name|nullptr
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|char
operator|*
operator|>
name|Blocks
expr_stmt|;
typedef|typedef
name|BumpPtrAllocatorImpl
operator|<
name|MallocAllocator
operator|,
literal|65536
operator|>
name|AllocatorTy
expr_stmt|;
name|AllocatorTy
name|MemPool
decl_stmt|;
block|}
struct|;
typedef|typedef
name|std
operator|::
name|set
operator|<
name|RegisterRef
operator|>
name|RegisterSet
expr_stmt|;
struct|struct
name|TargetOperandInfo
block|{
name|TargetOperandInfo
argument_list|(
specifier|const
name|TargetInstrInfo
operator|&
name|tii
argument_list|)
operator|:
name|TII
argument_list|(
argument|tii
argument_list|)
block|{}
name|virtual
operator|~
name|TargetOperandInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|bool
name|isPreserving
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|In
argument_list|,
name|unsigned
name|OpNum
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|isClobbering
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|In
argument_list|,
name|unsigned
name|OpNum
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|isFixedReg
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|In
argument_list|,
name|unsigned
name|OpNum
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|TargetInstrInfo
modifier|&
name|TII
decl_stmt|;
block|}
struct|;
comment|// Packed register reference. Only used for storage.
struct|struct
name|PackedRegisterRef
block|{
name|RegisterId
name|Reg
decl_stmt|;
name|uint32_t
name|MaskId
decl_stmt|;
block|}
struct|;
name|struct
name|LaneMaskIndex
range|:
name|private
name|IndexedSet
operator|<
name|LaneBitmask
operator|>
block|{
name|LaneMaskIndex
argument_list|()
operator|=
expr|default
block|;
name|LaneBitmask
name|getLaneMaskForIndex
argument_list|(
argument|uint32_t K
argument_list|)
specifier|const
block|{
return|return
name|K
operator|==
literal|0
operator|?
name|LaneBitmask
operator|::
name|getAll
argument_list|()
operator|:
name|get
argument_list|(
name|K
argument_list|)
return|;
block|}
name|uint32_t
name|getIndexForLaneMask
argument_list|(
argument|LaneBitmask LM
argument_list|)
block|{
name|assert
argument_list|(
name|LM
operator|.
name|any
argument_list|()
argument_list|)
block|;
return|return
name|LM
operator|.
name|all
argument_list|()
condition|?
literal|0
else|:
name|insert
argument_list|(
name|LM
argument_list|)
return|;
block|}
name|uint32_t
name|getIndexForLaneMask
argument_list|(
argument|LaneBitmask LM
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|LM
operator|.
name|any
argument_list|()
argument_list|)
block|;
return|return
name|LM
operator|.
name|all
argument_list|()
condition|?
literal|0
else|:
name|find
argument_list|(
name|LM
argument_list|)
return|;
block|}
expr|}
block|;    struct
name|NodeBase
block|{
name|public
operator|:
comment|// Make sure this is a POD.
name|NodeBase
argument_list|()
operator|=
expr|default
block|;
name|uint16_t
name|getType
argument_list|()
specifier|const
block|{
return|return
name|NodeAttrs
operator|::
name|type
argument_list|(
name|Attrs
argument_list|)
return|;
block|}
name|uint16_t
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|NodeAttrs
operator|::
name|kind
argument_list|(
name|Attrs
argument_list|)
return|;
block|}
name|uint16_t
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|NodeAttrs
operator|::
name|flags
argument_list|(
name|Attrs
argument_list|)
return|;
block|}
name|NodeId
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|Next
return|;
block|}
name|uint16_t
name|getAttrs
argument_list|()
specifier|const
block|{
return|return
name|Attrs
return|;
block|}
name|void
name|setAttrs
argument_list|(
argument|uint16_t A
argument_list|)
block|{
name|Attrs
operator|=
name|A
block|; }
name|void
name|setFlags
argument_list|(
argument|uint16_t F
argument_list|)
block|{
name|setAttrs
argument_list|(
name|NodeAttrs
operator|::
name|set_flags
argument_list|(
name|getAttrs
argument_list|()
argument_list|,
name|F
argument_list|)
argument_list|)
block|; }
comment|// Insert node NA after "this" in the circular chain.
name|void
name|append
argument_list|(
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|NA
argument_list|)
block|;
comment|// Initialize all members to 0.
name|void
name|init
argument_list|()
block|{
name|memset
argument_list|(
name|this
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
expr|*
name|this
argument_list|)
block|; }
name|void
name|setNext
argument_list|(
argument|NodeId N
argument_list|)
block|{
name|Next
operator|=
name|N
block|; }
name|protected
operator|:
name|uint16_t
name|Attrs
block|;
name|uint16_t
name|Reserved
block|;
name|NodeId
name|Next
block|;
comment|// Id of the next node in the circular chain.
comment|// Definitions of nested types. Using anonymous nested structs would make
comment|// this class definition clearer, but unnamed structs are not a part of
comment|// the standard.
block|struct
name|Def_struct
block|{
name|NodeId
name|DD
block|,
name|DU
block|;
comment|// Ids of the first reached def and use.
block|}
block|;     struct
name|PhiU_struct
block|{
name|NodeId
name|PredB
block|;
comment|// Id of the predecessor block for a phi use.
block|}
block|;     struct
name|Code_struct
block|{
name|void
operator|*
name|CP
block|;
comment|// Pointer to the actual code.
name|NodeId
name|FirstM
block|,
name|LastM
block|;
comment|// Id of the first member and last.
block|}
block|;     struct
name|Ref_struct
block|{
name|NodeId
name|RD
block|,
name|Sib
block|;
comment|// Ids of the reaching def and the sibling.
expr|union
block|{
name|Def_struct
name|Def
block|;
name|PhiU_struct
name|PhiU
block|;       }
block|;
expr|union
block|{
name|MachineOperand
operator|*
name|Op
block|;
comment|// Non-phi refs point to a machine operand.
name|PackedRegisterRef
name|PR
block|;
comment|// Phi refs store register info directly.
block|}
block|;     }
block|;
comment|// The actual payload.
expr|union
block|{
name|Ref_struct
name|Ref
block|;
name|Code_struct
name|Code
block|;     }
block|;   }
block|;
comment|// The allocator allocates chunks of 32 bytes for each node. The fact that
comment|// each node takes 32 bytes in memory is used for fast translation between
comment|// the node id and the node address.
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|NodeBase
argument_list|)
operator|<=
name|NodeAllocator
operator|::
name|NodeMemSize
argument_list|,
literal|"NodeBase must be at most NodeAllocator::NodeMemSize bytes"
argument_list|)
block|;
comment|//  typedef std::vector<NodeAddr<NodeBase*>> NodeList;
typedef|typedef
name|SmallVector
operator|<
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
operator|,
literal|4
operator|>
name|NodeList
expr_stmt|;
typedef|typedef
name|std
operator|::
name|set
operator|<
name|NodeId
operator|>
name|NodeSet
expr_stmt|;
name|struct
name|RefNode
range|:
name|public
name|NodeBase
block|{
name|RefNode
argument_list|()
operator|=
expr|default
block|;
name|RegisterRef
name|getRegRef
argument_list|(
argument|const DataFlowGraph&G
argument_list|)
specifier|const
block|;
name|MachineOperand
operator|&
name|getOp
argument_list|()
block|{
name|assert
argument_list|(
operator|!
operator|(
name|getFlags
argument_list|()
operator|&
name|NodeAttrs
operator|::
name|PhiRef
operator|)
argument_list|)
block|;
return|return
operator|*
name|Ref
operator|.
name|Op
return|;
block|}
name|void
name|setRegRef
argument_list|(
argument|RegisterRef RR
argument_list|,
argument|DataFlowGraph&G
argument_list|)
block|;
name|void
name|setRegRef
argument_list|(
name|MachineOperand
operator|*
name|Op
argument_list|,
name|DataFlowGraph
operator|&
name|G
argument_list|)
block|;
name|NodeId
name|getReachingDef
argument_list|()
specifier|const
block|{
return|return
name|Ref
operator|.
name|RD
return|;
block|}
name|void
name|setReachingDef
argument_list|(
argument|NodeId RD
argument_list|)
block|{
name|Ref
operator|.
name|RD
operator|=
name|RD
block|;     }
name|NodeId
name|getSibling
argument_list|()
specifier|const
block|{
return|return
name|Ref
operator|.
name|Sib
return|;
block|}
name|void
name|setSibling
argument_list|(
argument|NodeId Sib
argument_list|)
block|{
name|Ref
operator|.
name|Sib
operator|=
name|Sib
block|;     }
name|bool
name|isUse
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getType
argument_list|()
operator|==
name|NodeAttrs
operator|::
name|Ref
argument_list|)
block|;
return|return
name|getKind
argument_list|()
operator|==
name|NodeAttrs
operator|::
name|Use
return|;
block|}
name|bool
name|isDef
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getType
argument_list|()
operator|==
name|NodeAttrs
operator|::
name|Ref
argument_list|)
block|;
return|return
name|getKind
argument_list|()
operator|==
name|NodeAttrs
operator|::
name|Def
return|;
block|}
name|template
operator|<
name|typename
name|Predicate
operator|>
name|NodeAddr
operator|<
name|RefNode
operator|*
operator|>
name|getNextRef
argument_list|(
argument|RegisterRef RR
argument_list|,
argument|Predicate P
argument_list|,
argument|bool NextOnly
argument_list|,
argument|const DataFlowGraph&G
argument_list|)
block|;
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|getOwner
argument_list|(
specifier|const
name|DataFlowGraph
operator|&
name|G
argument_list|)
block|;   }
decl_stmt|;
name|struct
name|DefNode
range|:
name|public
name|RefNode
block|{
name|NodeId
name|getReachedDef
argument_list|()
specifier|const
block|{
return|return
name|Ref
operator|.
name|Def
operator|.
name|DD
return|;
block|}
name|void
name|setReachedDef
argument_list|(
argument|NodeId D
argument_list|)
block|{
name|Ref
operator|.
name|Def
operator|.
name|DD
operator|=
name|D
block|;     }
name|NodeId
name|getReachedUse
argument_list|()
specifier|const
block|{
return|return
name|Ref
operator|.
name|Def
operator|.
name|DU
return|;
block|}
name|void
name|setReachedUse
argument_list|(
argument|NodeId U
argument_list|)
block|{
name|Ref
operator|.
name|Def
operator|.
name|DU
operator|=
name|U
block|;     }
name|void
name|linkToDef
argument_list|(
argument|NodeId Self
argument_list|,
argument|NodeAddr<DefNode*> DA
argument_list|)
block|;   }
decl_stmt|;
name|struct
name|UseNode
range|:
name|public
name|RefNode
block|{
name|void
name|linkToDef
argument_list|(
argument|NodeId Self
argument_list|,
argument|NodeAddr<DefNode*> DA
argument_list|)
block|;   }
decl_stmt|;
name|struct
name|PhiUseNode
range|:
name|public
name|UseNode
block|{
name|NodeId
name|getPredecessor
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getFlags
argument_list|()
operator|&
name|NodeAttrs
operator|::
name|PhiRef
argument_list|)
block|;
return|return
name|Ref
operator|.
name|PhiU
operator|.
name|PredB
return|;
block|}
name|void
name|setPredecessor
argument_list|(
argument|NodeId B
argument_list|)
block|{
name|assert
argument_list|(
name|getFlags
argument_list|()
operator|&
name|NodeAttrs
operator|::
name|PhiRef
argument_list|)
block|;
name|Ref
operator|.
name|PhiU
operator|.
name|PredB
operator|=
name|B
block|;     }
expr|}
block|;    struct
name|CodeNode
operator|:
name|public
name|NodeBase
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|getCode
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|T
operator|>
operator|(
name|Code
operator|.
name|CP
operator|)
return|;
block|}
name|void
name|setCode
argument_list|(
argument|void *C
argument_list|)
block|{
name|Code
operator|.
name|CP
operator|=
name|C
block|;     }
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|getFirstMember
argument_list|(
argument|const DataFlowGraph&G
argument_list|)
specifier|const
block|;
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|getLastMember
argument_list|(
argument|const DataFlowGraph&G
argument_list|)
specifier|const
block|;
name|void
name|addMember
argument_list|(
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|NA
argument_list|,
specifier|const
name|DataFlowGraph
operator|&
name|G
argument_list|)
block|;
name|void
name|addMemberAfter
argument_list|(
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|MA
argument_list|,
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|NA
argument_list|,
specifier|const
name|DataFlowGraph
operator|&
name|G
argument_list|)
block|;
name|void
name|removeMember
argument_list|(
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|NA
argument_list|,
specifier|const
name|DataFlowGraph
operator|&
name|G
argument_list|)
block|;
name|NodeList
name|members
argument_list|(
argument|const DataFlowGraph&G
argument_list|)
specifier|const
block|;
name|template
operator|<
name|typename
name|Predicate
operator|>
name|NodeList
name|members_if
argument_list|(
argument|Predicate P
argument_list|,
argument|const DataFlowGraph&G
argument_list|)
specifier|const
block|;   }
block|;    struct
name|InstrNode
operator|:
name|public
name|CodeNode
block|{
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|getOwner
argument_list|(
specifier|const
name|DataFlowGraph
operator|&
name|G
argument_list|)
block|;   }
block|;    struct
name|PhiNode
operator|:
name|public
name|InstrNode
block|{
name|MachineInstr
operator|*
name|getCode
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
expr|}
block|;    struct
name|StmtNode
operator|:
name|public
name|InstrNode
block|{
name|MachineInstr
operator|*
name|getCode
argument_list|()
specifier|const
block|{
return|return
name|CodeNode
operator|::
name|getCode
operator|<
name|MachineInstr
operator|*
operator|>
operator|(
operator|)
return|;
block|}
expr|}
block|;    struct
name|BlockNode
operator|:
name|public
name|CodeNode
block|{
name|MachineBasicBlock
operator|*
name|getCode
argument_list|()
specifier|const
block|{
return|return
name|CodeNode
operator|::
name|getCode
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|void
name|addPhi
argument_list|(
name|NodeAddr
operator|<
name|PhiNode
operator|*
operator|>
name|PA
argument_list|,
specifier|const
name|DataFlowGraph
operator|&
name|G
argument_list|)
block|;   }
block|;    struct
name|FuncNode
operator|:
name|public
name|CodeNode
block|{
name|MachineFunction
operator|*
name|getCode
argument_list|()
specifier|const
block|{
return|return
name|CodeNode
operator|::
name|getCode
operator|<
name|MachineFunction
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|NodeAddr
operator|<
name|BlockNode
operator|*
operator|>
name|findBlock
argument_list|(
argument|const MachineBasicBlock *BB
argument_list|,
argument|const DataFlowGraph&G
argument_list|)
specifier|const
block|;
name|NodeAddr
operator|<
name|BlockNode
operator|*
operator|>
name|getEntryBlock
argument_list|(
specifier|const
name|DataFlowGraph
operator|&
name|G
argument_list|)
block|;   }
block|;    struct
name|DataFlowGraph
block|{
name|DataFlowGraph
argument_list|(
name|MachineFunction
operator|&
name|mf
argument_list|,
specifier|const
name|TargetInstrInfo
operator|&
name|tii
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|&
name|tri
argument_list|,
specifier|const
name|MachineDominatorTree
operator|&
name|mdt
argument_list|,
specifier|const
name|MachineDominanceFrontier
operator|&
name|mdf
argument_list|,
specifier|const
name|TargetOperandInfo
operator|&
name|toi
argument_list|)
block|;
name|NodeBase
operator|*
name|ptr
argument_list|(
argument|NodeId N
argument_list|)
specifier|const
block|;
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|ptr
argument_list|(
argument|NodeId N
argument_list|)
specifier|const
block|{
return|return
name|static_cast
operator|<
name|T
operator|>
operator|(
name|ptr
argument_list|(
name|N
argument_list|)
operator|)
return|;
block|}
name|NodeId
name|id
argument_list|(
argument|const NodeBase *P
argument_list|)
specifier|const
block|;
name|template
operator|<
name|typename
name|T
operator|>
name|NodeAddr
operator|<
name|T
operator|>
name|addr
argument_list|(
argument|NodeId N
argument_list|)
specifier|const
block|{
return|return
block|{
name|ptr
operator|<
name|T
operator|>
operator|(
name|N
operator|)
block|,
name|N
block|}
return|;
block|}
name|NodeAddr
operator|<
name|FuncNode
operator|*
operator|>
name|getFunc
argument_list|()
specifier|const
block|{
return|return
name|Func
return|;
block|}
name|MachineFunction
operator|&
name|getMF
argument_list|()
specifier|const
block|{
return|return
name|MF
return|;
block|}
specifier|const
name|TargetInstrInfo
operator|&
name|getTII
argument_list|()
specifier|const
block|{
return|return
name|TII
return|;
block|}
specifier|const
name|TargetRegisterInfo
operator|&
name|getTRI
argument_list|()
specifier|const
block|{
return|return
name|TRI
return|;
block|}
specifier|const
name|PhysicalRegisterInfo
operator|&
name|getPRI
argument_list|()
specifier|const
block|{
return|return
name|PRI
return|;
block|}
specifier|const
name|MachineDominatorTree
operator|&
name|getDT
argument_list|()
specifier|const
block|{
return|return
name|MDT
return|;
block|}
specifier|const
name|MachineDominanceFrontier
operator|&
name|getDF
argument_list|()
specifier|const
block|{
return|return
name|MDF
return|;
block|}
specifier|const
name|RegisterAggr
operator|&
name|getLiveIns
argument_list|()
specifier|const
block|{
return|return
name|LiveIns
return|;
block|}
expr|struct
name|DefStack
block|{
name|DefStack
argument_list|()
operator|=
expr|default
block|;
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Stack
operator|.
name|empty
argument_list|()
operator|||
name|top
argument_list|()
operator|==
name|bottom
argument_list|()
return|;
block|}
name|private
operator|:
typedef|typedef
name|NodeAddr
operator|<
name|DefNode
operator|*
operator|>
name|value_type
expr_stmt|;
block|struct
name|Iterator
block|{
typedef|typedef
name|DefStack
operator|::
name|value_type
name|value_type
expr_stmt|;
name|Iterator
operator|&
name|up
argument_list|()
block|{
name|Pos
operator|=
name|DS
operator|.
name|nextUp
argument_list|(
name|Pos
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|Iterator
operator|&
name|down
argument_list|()
block|{
name|Pos
operator|=
name|DS
operator|.
name|nextDown
argument_list|(
name|Pos
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|value_type
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Pos
operator|>=
literal|1
argument_list|)
block|;
return|return
name|DS
operator|.
name|Stack
index|[
name|Pos
operator|-
literal|1
index|]
return|;
block|}
specifier|const
name|value_type
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
name|assert
argument_list|(
name|Pos
operator|>=
literal|1
argument_list|)
block|;
return|return
operator|&
name|DS
operator|.
name|Stack
index|[
name|Pos
operator|-
literal|1
index|]
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Iterator
operator|&
name|It
operator|)
specifier|const
block|{
return|return
name|Pos
operator|==
name|It
operator|.
name|Pos
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Iterator
operator|&
name|It
operator|)
specifier|const
block|{
return|return
name|Pos
operator|!=
name|It
operator|.
name|Pos
return|;
block|}
name|private
operator|:
name|Iterator
argument_list|(
argument|const DefStack&S
argument_list|,
argument|bool Top
argument_list|)
block|;
comment|// Pos-1 is the index in the StorageType object that corresponds to
comment|// the top of the DefStack.
specifier|const
name|DefStack
operator|&
name|DS
block|;
name|unsigned
name|Pos
block|;
name|friend
expr|struct
name|DefStack
block|;       }
block|;
name|public
operator|:
typedef|typedef
name|Iterator
name|iterator
typedef|;
name|iterator
name|top
argument_list|()
specifier|const
block|{
return|return
name|Iterator
argument_list|(
operator|*
name|this
argument_list|,
name|true
argument_list|)
return|;
block|}
name|iterator
name|bottom
argument_list|()
specifier|const
block|{
return|return
name|Iterator
argument_list|(
operator|*
name|this
argument_list|,
name|false
argument_list|)
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|;
name|void
name|push
argument_list|(
argument|NodeAddr<DefNode*> DA
argument_list|)
block|{
name|Stack
operator|.
name|push_back
argument_list|(
name|DA
argument_list|)
block|; }
name|void
name|pop
argument_list|()
block|;
name|void
name|start_block
argument_list|(
argument|NodeId N
argument_list|)
block|;
name|void
name|clear_block
argument_list|(
argument|NodeId N
argument_list|)
block|;
name|private
operator|:
name|friend
expr|struct
name|Iterator
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|value_type
operator|>
name|StorageType
expr_stmt|;
name|bool
name|isDelimiter
argument_list|(
argument|const StorageType::value_type&P
argument_list|,
argument|NodeId N =
literal|0
argument_list|)
specifier|const
block|{
return|return
operator|(
name|P
operator|.
name|Addr
operator|==
name|nullptr
operator|)
operator|&&
operator|(
name|N
operator|==
literal|0
operator|||
name|P
operator|.
name|Id
operator|==
name|N
operator|)
return|;
block|}
name|unsigned
name|nextUp
argument_list|(
argument|unsigned P
argument_list|)
specifier|const
decl_stmt|;
name|unsigned
name|nextDown
argument_list|(
name|unsigned
name|P
argument_list|)
decl|const
decl_stmt|;
name|StorageType
name|Stack
decl_stmt|;
block|}
empty_stmt|;
comment|// Make this std::unordered_map for speed of accessing elements.
comment|// Map: Register (physical or virtual) -> DefStack
typedef|typedef
name|std
operator|::
name|unordered_map
operator|<
name|RegisterId
operator|,
name|DefStack
operator|>
name|DefStackMap
expr_stmt|;
name|void
name|build
parameter_list|(
name|unsigned
name|Options
init|=
name|BuildOptions
operator|::
name|None
parameter_list|)
function_decl|;
name|void
name|pushAllDefs
argument_list|(
name|NodeAddr
operator|<
name|InstrNode
operator|*
operator|>
name|IA
argument_list|,
name|DefStackMap
operator|&
name|DM
argument_list|)
decl_stmt|;
name|void
name|markBlock
parameter_list|(
name|NodeId
name|B
parameter_list|,
name|DefStackMap
modifier|&
name|DefM
parameter_list|)
function_decl|;
name|void
name|releaseBlock
parameter_list|(
name|NodeId
name|B
parameter_list|,
name|DefStackMap
modifier|&
name|DefM
parameter_list|)
function_decl|;
name|PackedRegisterRef
name|pack
parameter_list|(
name|RegisterRef
name|RR
parameter_list|)
block|{
return|return
block|{
name|RR
operator|.
name|Reg
block|,
name|LMI
operator|.
name|getIndexForLaneMask
argument_list|(
argument|RR.Mask
argument_list|)
block|}
return|;
block|}
name|PackedRegisterRef
name|pack
argument_list|(
name|RegisterRef
name|RR
argument_list|)
decl|const
block|{
return|return
block|{
name|RR
operator|.
name|Reg
block|,
name|LMI
operator|.
name|getIndexForLaneMask
argument_list|(
argument|RR.Mask
argument_list|)
block|}
return|;
block|}
name|RegisterRef
name|unpack
argument_list|(
name|PackedRegisterRef
name|PR
argument_list|)
decl|const
block|{
return|return
name|RegisterRef
argument_list|(
name|PR
operator|.
name|Reg
argument_list|,
name|LMI
operator|.
name|getLaneMaskForIndex
argument_list|(
name|PR
operator|.
name|MaskId
argument_list|)
argument_list|)
return|;
block|}
name|RegisterRef
name|makeRegRef
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|unsigned
name|Sub
argument_list|)
decl|const
decl_stmt|;
name|RegisterRef
name|makeRegRef
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|Op
argument_list|)
decl|const
decl_stmt|;
name|RegisterRef
name|restrictRef
argument_list|(
name|RegisterRef
name|AR
argument_list|,
name|RegisterRef
name|BR
argument_list|)
decl|const
decl_stmt|;
name|NodeAddr
operator|<
name|RefNode
operator|*
operator|>
name|getNextRelated
argument_list|(
argument|NodeAddr<InstrNode*> IA
argument_list|,
argument|NodeAddr<RefNode*> RA
argument_list|)
specifier|const
expr_stmt|;
name|NodeAddr
operator|<
name|RefNode
operator|*
operator|>
name|getNextImp
argument_list|(
argument|NodeAddr<InstrNode*> IA
argument_list|,
argument|NodeAddr<RefNode*> RA
argument_list|,
argument|bool Create
argument_list|)
expr_stmt|;
name|NodeAddr
operator|<
name|RefNode
operator|*
operator|>
name|getNextImp
argument_list|(
argument|NodeAddr<InstrNode*> IA
argument_list|,
argument|NodeAddr<RefNode*> RA
argument_list|)
specifier|const
expr_stmt|;
name|NodeAddr
operator|<
name|RefNode
operator|*
operator|>
name|getNextShadow
argument_list|(
argument|NodeAddr<InstrNode*> IA
argument_list|,
argument|NodeAddr<RefNode*> RA
argument_list|,
argument|bool Create
argument_list|)
expr_stmt|;
name|NodeAddr
operator|<
name|RefNode
operator|*
operator|>
name|getNextShadow
argument_list|(
argument|NodeAddr<InstrNode*> IA
argument_list|,
argument|NodeAddr<RefNode*> RA
argument_list|)
specifier|const
expr_stmt|;
name|NodeList
name|getRelatedRefs
argument_list|(
name|NodeAddr
operator|<
name|InstrNode
operator|*
operator|>
name|IA
argument_list|,
name|NodeAddr
operator|<
name|RefNode
operator|*
operator|>
name|RA
argument_list|)
decl|const
decl_stmt|;
name|NodeAddr
operator|<
name|BlockNode
operator|*
operator|>
name|findBlock
argument_list|(
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|{
return|return
name|BlockNodes
operator|.
name|at
argument_list|(
name|BB
argument_list|)
return|;
block|}
name|void
name|unlinkUse
argument_list|(
name|NodeAddr
operator|<
name|UseNode
operator|*
operator|>
name|UA
argument_list|,
name|bool
name|RemoveFromOwner
argument_list|)
block|{
name|unlinkUseDF
argument_list|(
name|UA
argument_list|)
expr_stmt|;
if|if
condition|(
name|RemoveFromOwner
condition|)
name|removeFromOwner
argument_list|(
name|UA
argument_list|)
expr_stmt|;
block|}
name|void
name|unlinkDef
argument_list|(
name|NodeAddr
operator|<
name|DefNode
operator|*
operator|>
name|DA
argument_list|,
name|bool
name|RemoveFromOwner
argument_list|)
block|{
name|unlinkDefDF
argument_list|(
name|DA
argument_list|)
expr_stmt|;
if|if
condition|(
name|RemoveFromOwner
condition|)
name|removeFromOwner
argument_list|(
name|DA
argument_list|)
expr_stmt|;
block|}
comment|// Some useful filters.
name|template
operator|<
name|uint16_t
name|Kind
operator|>
specifier|static
name|bool
name|IsRef
argument_list|(
argument|const NodeAddr<NodeBase*> BA
argument_list|)
block|{
return|return
name|BA
operator|.
name|Addr
operator|->
name|getType
argument_list|()
operator|==
name|NodeAttrs
operator|::
name|Ref
operator|&&
name|BA
operator|.
name|Addr
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
return|;
block|}
name|template
operator|<
name|uint16_t
name|Kind
operator|>
specifier|static
name|bool
name|IsCode
argument_list|(
argument|const NodeAddr<NodeBase*> BA
argument_list|)
block|{
return|return
name|BA
operator|.
name|Addr
operator|->
name|getType
argument_list|()
operator|==
name|NodeAttrs
operator|::
name|Code
operator|&&
name|BA
operator|.
name|Addr
operator|->
name|getKind
argument_list|()
operator|==
name|Kind
return|;
block|}
specifier|static
name|bool
name|IsDef
argument_list|(
specifier|const
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|BA
argument_list|)
block|{
return|return
name|BA
operator|.
name|Addr
operator|->
name|getType
argument_list|()
operator|==
name|NodeAttrs
operator|::
name|Ref
operator|&&
name|BA
operator|.
name|Addr
operator|->
name|getKind
argument_list|()
operator|==
name|NodeAttrs
operator|::
name|Def
return|;
block|}
specifier|static
name|bool
name|IsUse
argument_list|(
specifier|const
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|BA
argument_list|)
block|{
return|return
name|BA
operator|.
name|Addr
operator|->
name|getType
argument_list|()
operator|==
name|NodeAttrs
operator|::
name|Ref
operator|&&
name|BA
operator|.
name|Addr
operator|->
name|getKind
argument_list|()
operator|==
name|NodeAttrs
operator|::
name|Use
return|;
block|}
specifier|static
name|bool
name|IsPhi
argument_list|(
specifier|const
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|BA
argument_list|)
block|{
return|return
name|BA
operator|.
name|Addr
operator|->
name|getType
argument_list|()
operator|==
name|NodeAttrs
operator|::
name|Code
operator|&&
name|BA
operator|.
name|Addr
operator|->
name|getKind
argument_list|()
operator|==
name|NodeAttrs
operator|::
name|Phi
return|;
block|}
specifier|static
name|bool
name|IsPreservingDef
argument_list|(
specifier|const
name|NodeAddr
operator|<
name|DefNode
operator|*
operator|>
name|DA
argument_list|)
block|{
name|uint16_t
name|Flags
init|=
name|DA
operator|.
name|Addr
operator|->
name|getFlags
argument_list|()
decl_stmt|;
return|return
operator|(
name|Flags
operator|&
name|NodeAttrs
operator|::
name|Preserving
operator|)
operator|&&
operator|!
operator|(
name|Flags
operator|&
name|NodeAttrs
operator|::
name|Undef
operator|)
return|;
block|}
name|private
label|:
name|void
name|reset
parameter_list|()
function_decl|;
name|RegisterSet
name|getLandingPadLiveIns
argument_list|()
specifier|const
expr_stmt|;
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|newNode
argument_list|(
argument|uint16_t Attrs
argument_list|)
expr_stmt|;
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|cloneNode
argument_list|(
specifier|const
name|NodeAddr
operator|<
name|NodeBase
operator|*
operator|>
name|B
argument_list|)
expr_stmt|;
name|NodeAddr
operator|<
name|UseNode
operator|*
operator|>
name|newUse
argument_list|(
argument|NodeAddr<InstrNode*> Owner
argument_list|,
argument|MachineOperand&Op
argument_list|,
argument|uint16_t Flags = NodeAttrs::None
argument_list|)
expr_stmt|;
name|NodeAddr
operator|<
name|PhiUseNode
operator|*
operator|>
name|newPhiUse
argument_list|(
argument|NodeAddr<PhiNode*> Owner
argument_list|,
argument|RegisterRef RR
argument_list|,
argument|NodeAddr<BlockNode*> PredB
argument_list|,
argument|uint16_t Flags = NodeAttrs::PhiRef
argument_list|)
expr_stmt|;
name|NodeAddr
operator|<
name|DefNode
operator|*
operator|>
name|newDef
argument_list|(
argument|NodeAddr<InstrNode*> Owner
argument_list|,
argument|MachineOperand&Op
argument_list|,
argument|uint16_t Flags = NodeAttrs::None
argument_list|)
expr_stmt|;
name|NodeAddr
operator|<
name|DefNode
operator|*
operator|>
name|newDef
argument_list|(
argument|NodeAddr<InstrNode*> Owner
argument_list|,
argument|RegisterRef RR
argument_list|,
argument|uint16_t Flags = NodeAttrs::PhiRef
argument_list|)
expr_stmt|;
name|NodeAddr
operator|<
name|PhiNode
operator|*
operator|>
name|newPhi
argument_list|(
name|NodeAddr
operator|<
name|BlockNode
operator|*
operator|>
name|Owner
argument_list|)
expr_stmt|;
name|NodeAddr
operator|<
name|StmtNode
operator|*
operator|>
name|newStmt
argument_list|(
name|NodeAddr
operator|<
name|BlockNode
operator|*
operator|>
name|Owner
argument_list|,
name|MachineInstr
operator|*
name|MI
argument_list|)
expr_stmt|;
name|NodeAddr
operator|<
name|BlockNode
operator|*
operator|>
name|newBlock
argument_list|(
name|NodeAddr
operator|<
name|FuncNode
operator|*
operator|>
name|Owner
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|)
expr_stmt|;
name|NodeAddr
operator|<
name|FuncNode
operator|*
operator|>
name|newFunc
argument_list|(
name|MachineFunction
operator|*
name|MF
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|Predicate
operator|>
name|std
operator|::
name|pair
operator|<
name|NodeAddr
operator|<
name|RefNode
operator|*
operator|>
operator|,
name|NodeAddr
operator|<
name|RefNode
operator|*
operator|>>
name|locateNextRef
argument_list|(
argument|NodeAddr<InstrNode*> IA
argument_list|,
argument|NodeAddr<RefNode*> RA
argument_list|,
argument|Predicate P
argument_list|)
specifier|const
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|NodeId
operator|,
name|RegisterSet
operator|>
name|BlockRefsMap
expr_stmt|;
name|void
name|buildStmt
argument_list|(
name|NodeAddr
operator|<
name|BlockNode
operator|*
operator|>
name|BA
argument_list|,
name|MachineInstr
operator|&
name|In
argument_list|)
decl_stmt|;
name|void
name|buildBlockRefs
argument_list|(
name|NodeAddr
operator|<
name|BlockNode
operator|*
operator|>
name|BA
argument_list|,
name|BlockRefsMap
operator|&
name|RefM
argument_list|)
decl_stmt|;
name|void
name|recordDefsForDF
argument_list|(
name|BlockRefsMap
operator|&
name|PhiM
argument_list|,
name|BlockRefsMap
operator|&
name|RefM
argument_list|,
name|NodeAddr
operator|<
name|BlockNode
operator|*
operator|>
name|BA
argument_list|)
decl_stmt|;
name|void
name|buildPhis
argument_list|(
name|BlockRefsMap
operator|&
name|PhiM
argument_list|,
name|BlockRefsMap
operator|&
name|RefM
argument_list|,
name|NodeAddr
operator|<
name|BlockNode
operator|*
operator|>
name|BA
argument_list|)
decl_stmt|;
name|void
name|removeUnusedPhis
parameter_list|()
function_decl|;
name|void
name|pushClobbers
argument_list|(
name|NodeAddr
operator|<
name|InstrNode
operator|*
operator|>
name|IA
argument_list|,
name|DefStackMap
operator|&
name|DM
argument_list|)
decl_stmt|;
name|void
name|pushDefs
argument_list|(
name|NodeAddr
operator|<
name|InstrNode
operator|*
operator|>
name|IA
argument_list|,
name|DefStackMap
operator|&
name|DM
argument_list|)
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|linkRefUp
argument_list|(
name|NodeAddr
operator|<
name|InstrNode
operator|*
operator|>
name|IA
argument_list|,
name|NodeAddr
operator|<
name|T
operator|>
name|TA
argument_list|,
name|DefStack
operator|&
name|DS
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|Predicate
operator|>
name|void
name|linkStmtRefs
argument_list|(
argument|DefStackMap&DefM
argument_list|,
argument|NodeAddr<StmtNode*> SA
argument_list|,
argument|Predicate P
argument_list|)
expr_stmt|;
name|void
name|linkBlockRefs
argument_list|(
name|DefStackMap
operator|&
name|DefM
argument_list|,
name|NodeAddr
operator|<
name|BlockNode
operator|*
operator|>
name|BA
argument_list|)
decl_stmt|;
name|void
name|unlinkUseDF
argument_list|(
name|NodeAddr
operator|<
name|UseNode
operator|*
operator|>
name|UA
argument_list|)
decl_stmt|;
name|void
name|unlinkDefDF
argument_list|(
name|NodeAddr
operator|<
name|DefNode
operator|*
operator|>
name|DA
argument_list|)
decl_stmt|;
name|void
name|removeFromOwner
argument_list|(
name|NodeAddr
operator|<
name|RefNode
operator|*
operator|>
name|RA
argument_list|)
block|{
name|NodeAddr
operator|<
name|InstrNode
operator|*
operator|>
name|IA
operator|=
name|RA
operator|.
name|Addr
operator|->
name|getOwner
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
name|IA
operator|.
name|Addr
operator|->
name|removeMember
argument_list|(
name|RA
argument_list|,
operator|*
name|this
argument_list|)
expr_stmt|;
block|}
name|MachineFunction
modifier|&
name|MF
decl_stmt|;
specifier|const
name|TargetInstrInfo
modifier|&
name|TII
decl_stmt|;
specifier|const
name|TargetRegisterInfo
modifier|&
name|TRI
decl_stmt|;
specifier|const
name|PhysicalRegisterInfo
name|PRI
decl_stmt|;
specifier|const
name|MachineDominatorTree
modifier|&
name|MDT
decl_stmt|;
specifier|const
name|MachineDominanceFrontier
modifier|&
name|MDF
decl_stmt|;
specifier|const
name|TargetOperandInfo
modifier|&
name|TOI
decl_stmt|;
name|RegisterAggr
name|LiveIns
decl_stmt|;
name|NodeAddr
operator|<
name|FuncNode
operator|*
operator|>
name|Func
expr_stmt|;
name|NodeAllocator
name|Memory
decl_stmt|;
comment|// Local map:  MachineBasicBlock -> NodeAddr<BlockNode*>
name|std
operator|::
name|map
operator|<
name|MachineBasicBlock
operator|*
operator|,
name|NodeAddr
operator|<
name|BlockNode
operator|*
operator|>>
name|BlockNodes
expr_stmt|;
comment|// Lane mask map.
name|LaneMaskIndex
name|LMI
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// struct DataFlowGraph
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Predicate
operator|>
name|NodeAddr
operator|<
name|RefNode
operator|*
operator|>
name|RefNode
operator|::
name|getNextRef
argument_list|(
argument|RegisterRef RR
argument_list|,
argument|Predicate P
argument_list|,
argument|bool NextOnly
argument_list|,
argument|const DataFlowGraph&G
argument_list|)
block|{
comment|// Get the "Next" reference in the circular list that references RR and
comment|// satisfies predicate "Pred".
name|auto
name|NA
operator|=
name|G
operator|.
name|addr
operator|<
name|NodeBase
operator|*
operator|>
operator|(
name|getNext
argument_list|()
operator|)
block|;
while|while
condition|(
name|NA
operator|.
name|Addr
operator|!=
name|this
condition|)
block|{
if|if
condition|(
name|NA
operator|.
name|Addr
operator|->
name|getType
argument_list|()
operator|==
name|NodeAttrs
operator|::
name|Ref
condition|)
block|{
name|NodeAddr
operator|<
name|RefNode
operator|*
operator|>
name|RA
operator|=
name|NA
expr_stmt|;
if|if
condition|(
name|RA
operator|.
name|Addr
operator|->
name|getRegRef
argument_list|(
name|G
argument_list|)
operator|==
name|RR
operator|&&
name|P
argument_list|(
name|NA
argument_list|)
condition|)
return|return
name|NA
return|;
if|if
condition|(
name|NextOnly
condition|)
break|break;
name|NA
operator|=
name|G
operator|.
name|addr
operator|<
name|NodeBase
operator|*
operator|>
operator|(
name|NA
operator|.
name|Addr
operator|->
name|getNext
argument_list|()
operator|)
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
comment|// We've hit the beginning of the chain.
name|assert
argument_list|(
name|NA
operator|.
name|Addr
operator|->
name|getType
argument_list|()
operator|==
name|NodeAttrs
operator|::
name|Code
argument_list|)
expr_stmt|;
name|NodeAddr
operator|<
name|CodeNode
operator|*
operator|>
name|CA
operator|=
name|NA
expr_stmt|;
name|NA
operator|=
name|CA
operator|.
name|Addr
operator|->
name|getFirstMember
argument_list|(
name|G
argument_list|)
expr_stmt|;
block|}
end_else

begin_comment
unit|}
comment|// Return the equivalent of "nullptr" if such a node was not found.
end_comment

begin_expr_stmt
unit|return
name|NodeAddr
operator|<
name|RefNode
operator|*
operator|>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|Predicate
operator|>
name|NodeList
name|CodeNode
operator|::
name|members_if
argument_list|(
argument|Predicate P
argument_list|,
argument|const DataFlowGraph&G
argument_list|)
specifier|const
block|{
name|NodeList
name|MM
block|;
name|auto
name|M
operator|=
name|getFirstMember
argument_list|(
name|G
argument_list|)
block|;
if|if
condition|(
name|M
operator|.
name|Id
operator|==
literal|0
condition|)
return|return
name|MM
return|;
end_expr_stmt

begin_while
while|while
condition|(
name|M
operator|.
name|Addr
operator|!=
name|this
condition|)
block|{
if|if
condition|(
name|P
argument_list|(
name|M
argument_list|)
condition|)
name|MM
operator|.
name|push_back
argument_list|(
name|M
argument_list|)
expr_stmt|;
name|M
operator|=
name|G
operator|.
name|addr
operator|<
name|NodeBase
operator|*
operator|>
operator|(
name|M
operator|.
name|Addr
operator|->
name|getNext
argument_list|()
operator|)
expr_stmt|;
block|}
end_while

begin_return
return|return
name|MM
return|;
end_return

begin_expr_stmt
unit|}     template
operator|<
name|typename
name|T
operator|>
expr|struct
name|Print
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|Print
operator|<
name|T
operator|>
operator|&
name|P
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|Print
block|{
name|Print
argument_list|(
specifier|const
name|T
operator|&
name|x
argument_list|,
specifier|const
name|DataFlowGraph
operator|&
name|g
argument_list|)
operator|:
name|Obj
argument_list|(
name|x
argument_list|)
block|,
name|G
argument_list|(
argument|g
argument_list|)
block|{}
specifier|const
name|T
operator|&
name|Obj
block|;
specifier|const
name|DataFlowGraph
operator|&
name|G
block|;   }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|PrintNode
operator|:
name|Print
operator|<
name|NodeAddr
operator|<
name|T
operator|>>
block|{
name|PrintNode
argument_list|(
specifier|const
name|NodeAddr
operator|<
name|T
operator|>
operator|&
name|x
argument_list|,
specifier|const
name|DataFlowGraph
operator|&
name|g
argument_list|)
operator|:
name|Print
operator|<
name|NodeAddr
operator|<
name|T
operator|>>
operator|(
name|x
operator|,
name|g
operator|)
block|{}
block|}
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// end namespace rdf
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_HEXAGON_RDFGRAPH_H
end_comment

end_unit

