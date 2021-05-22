rfp = 1

line = input().split(' ')
n_req = int(line[0])
n_prop = int(line[1])


while n_req != 0 and n_prop != 0:
    m_price = -1
    m_compliance = -1
    m_name = ""
    for i in range(n_req): input()

    for i in range(n_prop):
        name = input()
        line = input().split(' ')
        price = float(line[0])
        n_req_met = int(line[1])


        for j in range(n_req_met): input()

        compliance = n_req_met / n_req

        if (compliance > m_compliance):
            m_compliance = compliance
            m_price = price
            m_name = name
        elif (compliance == m_compliance and price < m_price):
            m_compliance = compliance
            m_price = price
            m_name = name

    print("RFP #{}\n{}".format(rfp, m_name))

    rfp += 1
    line = input().split(' ')
    n_req = int(line[0])
    n_prop = int(line[1])

    if(n_req != 0 and n_prop != 0): print()
