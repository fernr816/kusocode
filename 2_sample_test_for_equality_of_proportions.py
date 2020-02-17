# 2群の比率の差の検定
def test_proportions(sample1, sample2):
    """
    in: 
        sample1: 標本1
        sample2: 比較対象標本2
    """
    
    # 有意水準
    z0025 = 1.96
    
    # 標本比率
    p1 = sample1 / sample1.sum()
    p2 = sample2 / sample2.sum()
    p = (sample1 + sample2) / (sample1.sum() + sample2.sum())

    # z
    z = (p1 - p2) / np.sqrt(p*(1-p)*((1/sample1.sum()) + (1/sample2.sum())))
    print("z = ", z)

    # 結果を出力
    if (-z0025 <=  z) & (z <= z0025):
        print("有意差なし")
    else:
        print("有意差あり")
