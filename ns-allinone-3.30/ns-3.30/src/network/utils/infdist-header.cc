/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2020 Michał Barciś
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Michał Barciś <mbarcis@mbarcis.net>
 */

#include <iostream>
#include "ns3/header.h"
#include "infdist-header.h"

namespace ns3 {

InfDistHeader::InfDistHeader ()
{
  // we must provide a public default constructor, 
  // implicit or explicit, but never private.
    
}
InfDistHeader::~InfDistHeader ()
{
}

TypeId
InfDistHeader::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::InfDistHeader")
    .SetParent<Header> ()
    .AddConstructor<InfDistHeader> ()
  ;
  return tid;
}
TypeId
InfDistHeader::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}

void
InfDistHeader::Print (std::ostream &os) const
{
  // This method is invoked by the packet printing
  // routines to print the content of my header.
  //os << "data=" << m_data << std::endl;
  os << 
      data_type << 
      "@" << timestamp << "; " <<
      " from " << sender <<
      "; data=" << data;
}
uint32_t
InfDistHeader::GetSerializedSize (void) const
{
  return 15+this->data_len;
}
void
InfDistHeader::Serialize (Buffer::Iterator start) const
{
  // we can serialize two bytes at the start of the buffer.
  // we write them in network byte order.
  start.WriteHtonU64 (this->timestamp);
  start.WriteHtonU32 (this->sender);
  start.WriteU8 (this->data_type);
  start.WriteHtonU16 (this->data_len);
  for(int i=0; i<this->data_len; i++) {
    start.WriteU8 (this->data[i]);
  }
}
uint32_t
InfDistHeader::Deserialize (Buffer::Iterator start)
{
  // we can deserialize two bytes from the start of the buffer.
  // we read them in network byte order and store them
  // in host byte order.
  this->timestamp = start.ReadNtohU64 ();
  this->sender = start.ReadNtohU32 ();
  this->data_type = start.ReadU8 ();
  this->data_len = start.ReadNtohU16 ();
  for(int i=0; i<this->data_len; i++) {
      this->data[i] = start.ReadU8 ();
  }
  // we return the number of bytes effectively read.
  return this->GetSerializedSize();
}

void 
InfDistHeader::SetTimestamp (uint64_t timestamp)
{
    this->timestamp = timestamp;
}
uint64_t 
InfDistHeader::GetTimestamp (void) 
{
    return this->timestamp;
}
void 
InfDistHeader::SetSender (uint32_t sender)
{
    this->sender = sender;
}
uint32_t 
InfDistHeader::GetSender (void) 
{
    return this->sender;
}
void 
InfDistHeader::SetDataType (char type)
{
    this->data_type = type;
}
char 
InfDistHeader::GetDataType (void) 
{
    return this->data_type;
}
void 
InfDistHeader::SetData (uint16_t len, char * data)
{
    this->data_len = len;
    for(uint16_t i=0; i<this->data_len; i++) {
        this->data[i] = data[i];
    }
}
char *
InfDistHeader::GetData (void) 
{
    return this->data;
}

} // namespace ns3
