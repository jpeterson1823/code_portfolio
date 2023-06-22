import re

class IPv4:
    @classmethod
    def loopback(cls):
        return cls("127.0.0.1", "4")

    def __init__(self, ipv4: str, subnet:str):
        # break ipv4 string into octets
        self.octets = []
        for s in ipv4.split("."):
            self.octets.append(int(s))

        self.subm = int(subnet)
        self.bitmask = self._calcBitMask()

    def _calcBitMask(self) -> list[int]:
        host_bits = 32 - self.subm

        mask = []
        j = 0
        count = 0
        for i in range(self.subm):
            if count == 8:
                mask.append(j)
                j = 0
                count = 0
            j <<=1
            j += 1
            count += 1

        for i in range(host_bits):
            if count == 8:
                mask.append(j)
                j = 0
                count = 0
            j <<=1
            count += 1
        mask.append(j)
        return mask
    
    def addrstrs(self) -> tuple[str, str]:
        ipv4 = ""
        mask = ""
        for i in range(4):
            ipv4 += str(self.octets[i]) + '.'
            mask += str(self.bitmask[i]) + '.'
        ipv4 = ipv4[:len(ipv4)-1]
        mask = mask[:len(mask)-1]
        return (ipv4, mask)
   
    def subnets(self) -> list[list[int]]:
        # determine interesting octet
        i = 0
        for j in range(4):
            if self.bitmask[j] != 255:
                break
            i += 1
        
        # determine step
        step = 256 - self.bitmask[i]
        print(f"interesting octet: #{i+1} ({self.bitmask[i]})")
        print(f"step: {step}")

        # calculate subnets
        addr = self.octets[0:i] + [0]*(4-i)
        subnets = [addr.copy()]
        while addr[i] + step < 255:
            addr[i] += step
            subnets.append(addr.copy())
        return subnets

    def __str__(self) -> str: 
        ipv4, mask = self.addrstrs()
        return f"IPv4: {ipv4}/{self.subm} BITMASK {mask}"
    

def getInput() -> IPv4:
    raw = input("Network: ")
    prefix = re.match('''^\d\d?\d?\.\d\d?\d?\.\d\d?\d?\.\d\d?\d?\/\d\d?''', raw)
    normal = re.match('''^\d\d?\d?\.\d\d?\d?\.\d\d?\d?\.\d\d?\d?''', raw)

    if prefix:
        print("Address was provided in prefix form.")
        subnet = raw.split('/')[1]
        return IPv4(raw.split('/')[0], subnet)
    else:
        print("Address subnet mask was not provided.")
        if normal:
            subnet = input("Subnet Mask (Classful Form): ")
            return IPv4(normal.group(0), subnet)
    return IPv4.loopback()


if __name__ == "__main__":
    network = getInput()
    print(network)
    for subnet in network.subnets():
        print(subnet)
