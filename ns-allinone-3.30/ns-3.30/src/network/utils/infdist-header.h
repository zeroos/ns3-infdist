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

#ifndef INFDIST_HEADER_H
#define INFDIST_HEADER_H

#include "ns3/header.h"
#include <string>
#include "ns3/mac48-address.h"

namespace ns3 {

class InfDistHeader : public Header 
{
public:
    InfDistHeader ();
    virtual ~InfDistHeader ();

    void SetTimestamp (uint64_t timestamp);
    uint64_t GetTimestamp (void);
    void SetSender (uint32_t sender);
    uint32_t GetSender (void);
    void SetDataType (char type);
    char GetDataType (void);
    void SetData (uint16_t len, char * data);
    char * GetData (void);
  
    static TypeId GetTypeId (void);
    virtual TypeId GetInstanceTypeId (void) const;
    virtual void Print (std::ostream &os) const;
    virtual void Serialize (Buffer::Iterator start) const;
    virtual uint32_t Deserialize (Buffer::Iterator start);
    virtual uint32_t GetSerializedSize (void) const;
private:
    uint64_t timestamp = 0;
    uint32_t sender = 0;
    char data_type = 0;
    uint16_t data_len = 0;
    char data[1024] = "";
};

} // namespace ns3


#endif /* INFDIST_HEADER_H */
