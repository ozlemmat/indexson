try:
    import streamlit as st
    import streamlit.components.v1 as components
    from PIL import Image
except Exception as e:
    print(e)
# Resimlerle ilgili bilgiler
STYLE = """
    <style>
    img {
        max-width: 100%;
    }
    </style>
    """
#sayfalar
st.set_page_config(
    page_title="Tarıma Yeni Bir Soluk",)
#sekmeler
tabs = ["Giriş", "Akıllı Tarım ", "Bulanık Mantık ", "Blokzincir "]
page = st.sidebar.radio("Sayfalar", tabs)
#resimler
image1 = Image.open("tarim-teknolojileri.png")
image2 = Image.open("meta.jpg")
image3 = Image.open("bulanik1.png")
image4 = Image.open("e_1_0.png")
image5 = Image.open("e_2_0.png")
image6 = Image.open("e_3_0.png")
image7 = Image.open("e_4_0.png")
image8 = Image.open("4_0.png")
image9 = Image.open("Blockchain.png")
image10 = Image.open("block.png")
image11 = Image.open("tarim_blokzinciri.png")
image12 = Image.open("akilli_sera.png")
image13 = Image.open("python.png")
image14 = Image.open("arduino.png")
image15 = Image.open("pycharm.png")
image16 = Image.open("arduino_ide.png")
image17 = Image.open("anasayfa.png")
image18= Image.open("akillli_tarim_1.png")
image19=Image.open("esp32.png")
image20 = Image.open("dht11-isi-ve-nem-sensoru-kart-14197-17-B.jpg")
image21=Image.open("YL69-800x800.jpg")
image22=Image.open("download.jpg")
image23=Image.open("4-pinli-push-buton-siyah-6x6x5mm-11612-51-B.jpg")
image24=Image.open("16x2-lcd-ekran-yesil-uzerine-siyah-27412-11-B.jpg")
#video

#giriş sayfası
if page == "Giriş":
    st.markdown("<h1 style='text-align:center;'> Tarıma Yeni Bir Soluk</h1>", unsafe_allow_html=True)
    st.image(image2)
    st.markdown("<p style='text-align:center;'>Metamask Hesabına Başarılı Bir Şekilde Giriş Yaptınız..<br> Aşağıda Bulunan Sekmelerden Kullanıcı Seçiminizi Yapınız</p>", unsafe_allow_html=True)
    kullanicilar = st.selectbox("Kullanıcılar", ("Kullanıcılar","Çiftlik Sahibi Erişim Sayfası", "Çiftçi Erişim Sayfası", "Elektrik Teknikeri Erişim Sayfası","Su Tesisatçısı Erişim Sayfası","Teknik Eleman Erişim Sayfası","Müşteri Erişim Sayfası"))
    if kullanicilar=="":
        st.write("kullanıcılar")
    elif kullanicilar=="Çiftlik Sahibi Erişim Sayfası":
     st.markdown("<a href='http://192.168.1.6/' target='_parent'>Çiftlik Sahibi</a>" , unsafe_allow_html=True)
    elif kullanicilar==("Çiftçi Erişim Sayfası"):
        st.markdown("<a href='http://192.168.1.6/' target='_parent'>Metamask ile Giriş</a>" , unsafe_allow_html=True)
    elif kullanicilar==("Elektrik Teknikeri Erişim Sayfası"):
        st.markdown("<a href='http://192.168.1.6/' target='_parent'>Metamask ile Giriş</a>", unsafe_allow_html=True)
    elif kullanicilar==("Su Tesisatçısı Erişim Sayfası"):
        st.markdown("<a href='http://192.168.1.6/' target='_parent'>Metamask ile Giriş</a>", unsafe_allow_html=True)
    elif kullanicilar==("Teknik Eleman Erişim Sayfası"):
        st.markdown("<a href='http://192.168.1.6/' target='_parent'>Metamask ile Giriş</a>",            unsafe_allow_html=True)
    elif kullanicilar==("Müşteri Erişim Sayfası"):
        st.markdown("<a href='http://192.168.1.6/' target='_parent'>Metamask ile Giriş</a>",            unsafe_allow_html=True)
#akıllı tarım sayfası
elif page == "Akıllı Tarım ":
    st.markdown("<h1 style='text-align:center;'> Akıllı Tarım</h1>", unsafe_allow_html=True)
    st.image(image1, caption="Akıllı Tarım Teknolojileri")
    st.markdown("""\n[Tarım sektöründe](https://www.researchgate.net/profile/Aylin-Kirkaya/publication/339029285_AKILLI_TARIM_TEKNOLOJILERI_UYGULAMALARI/links/5e398bf492851c7f7f1ce771/AKILLI-TARIM-TEKNOLOJILERI-UYGULAMALARI.pdf) iklim değişikliğinin de etkisi ile kontrol edilemeyen faktörler ürün kayıplarını artırmaktadır. Yapılan araştırmalar toprağın niteliği ve organik yapısının dikkate alınması, drenaj ve sulama uygulamaları, tohum seçim ve ekim metodu, toprak&bitki besleme uygulamaları, bitki koruma uygulamaları, hasat teknikleri vb. konularda geleneksel metotların profesyonel bir şekilde izleme olanağı sunmadığını göstermektedir. Dijital izleme metotlarında sensör, kamera, uydu vb. kanallardan toplanan bilgiler sistematik olarak ve konum bazlı depolanmakta, çeşitli algoritmalar kullanılarak anlamlandırılıp sebep sonuç ilişkileri raporlanabilmekte, uygun veriler cep telefonlarından anlık bilgi olarak iletilebilmektedir.Endüstri 4.0 ile hayatımıza giren dijital teknolojiler karar destek platformlarına veri sağlayan aracılar görevini görmektedir. """,unsafe_allow_html=True)
    st.image(image12, caption="Akıllı Tarım")
    st.markdown("""\nTarım alanlarının genişlemek yerine daraldığı dünyamızda girdi maliyetlerini azaltıp verimi artırmak gereği açıktır. Bunun için en etkili çözüm yöntemlerinden biri problemin farkına varıp uygulama hatalarına karşı önleyici, zamanında ve doğru müdahalede bulunmaktır. """)
    st.subheader("IoT (Nesnelerin İnterneti) ")
    st.markdown("""90’ların başında Cambridge’li akademisyenlerin kahve makinasını uzaktan izlemesi ile hayatımıza girdiği kabul edilir. Çeşitli ağ, sensör, kablosuz bağlantı sistemleri ile cihazların birbiri ile iletişim kurabilmesi olarak ifade edilebilir. Pek çok sektörde gerçek zamanlı, yüksek doğrulukta dijital bilgi trafiği diğer teknolojiler ile birleştiğinde süreç ve hizmet yönetiminde sağladığı faydalar nedeniyle hızla kabul görmüştür.Akıllı evler, şehirler, enerji sistemleri, haberleşme, lojistik, tarım, sağlık, endüstri vb birçok alanda günümüzde 20 milyar cihazın IoT teknolojisi ile birbirine bağlı olduğu değerlendirilmektedir. Artan bilgi trafiğinde olası güvenlik sorunlarına karşı blockchain teknolojisi ile birleşeceği düşünülmektedir. Bulut sistemlerinde ise veri işlenip depolanmaktadır.""")
    st.subheader("GIS (Coğrafi Bilgi Sistemleri)")
    st.markdown("""Her türlü coğrafi referanslı bilginin etkin olarak elde edilmesi, depolanması, güncellenmesi, kullanılması, analizi ve görüntülenmesi için bilgisayar donanımı, yazılımı, personel ve yöntemlerin organize olarak bir araya toplanmasıdır.""")
    st.subheader("AI (Yapay Zeka)")
    st.markdown("""Yapay zeka olarak ifade edilen kavram birçok tanımı olmakla beraber esasen insan tarafından dizayn edilen bir sistemi anlatmaktadır. Çeşitli algoritmalarla bilginin makinaya öğretilmesi, bütünleşik bir yaklaşımla sisteme sürekli besleme yapılarak karşılaştırma verilerinin de kullanımı ile bir nevi muhakeme yeteneği kazandırılması ve çıktının güvenilirliğinin artırılmasıdır. İnsan zekasının sınırları bilinmemekle birlikte çoklu, karmaşık ve büyük miktarda veri işlemede makine desteğine ihtiyaç duymakta, yaptığı kurgu ile teknoloji ve bilgi sistemini amaçları doğrultusunda kullanabilmektedir. Bu tür sistemlerle karar alma mekanizması geliştirilmekte ve hızlandırılmaktadır.""")
    st.image(image17, width=800, caption="Akıllı Tarım ve Blokzinciri")
    endustri_cesitleri = st.selectbox("Endüstri Çeşitleri",("Endüstri Çeşitleri","Endüstri 1.0", "Endüstri 2.0", "Endüstri 3.0", "Endüstri 4.0"))
    if endustri_cesitleri == " ":
        st.write("Endüstri Çeşitleri")
    elif endustri_cesitleri == "Endüstri 1.0":
        st.write("Birinci Sanayi Devrimi, 18. yüzyılda buhar gücünün kullanılması ve üretimin mekanizasyonu ile başladı. Tarım ve el sanatları ekonomisinden makinelerin egemen olduğu ve madencilik, tekstil, cam ve tarım gibi endüstrileri önemli ölçüde etkilediği bir ekonomiye geçişi işaret etti. Daha önce basit çıkrıklarda üretilen iplikler, mekanize versiyon ile aynı anda sekiz kat daha fazla hacim elde etti. ")
        st.image(image4, caption="Endüstri 1.0")
    elif endustri_cesitleri == "Endüstri 2.0":
        st.write("Seri imalatın ortaya çıkması ile seri imalatın verimliliği üzerine birçok çalışma yapılmıştır. Bu çalışmaların başında Taylor’un araştırmaları gelmektedir. 1900 yılında çelik malzemelerin işlenmesi için kullanılan ve kendi adıyla anılan Taylor-White yüksek hız takımlarını işleme yöntemi ortaya çıkmıştır. Taylor üretimde verimlilik konusunda birçok çalışma yapmış ve Endüstri Mühendisliği mesleğinin doğmasını sağlamıştır. Ayrıca Taylor bilimsel yönetim ilkeleri ortaya koymuştur. Üretimde verimsizliliğin nedenlerini tespit edip çözüm yolları aramıştır. Bilimsel Yönetim Esasları yönetimin esas hedefinin maksimum işveren refahını sağlamak olduğunu, bunun ancak maksimum üretkenlikle sağlanabileceğini belirtmiştir. Yönetimin ve çalışanın asıl hedefinin eğitim yoluyla çalışanın yeteneklerinin geliştirilmesi gerektiği anlatılmıştır. Bu sayede herkes doğal yeteneklerine uygun olduğu işlerde en üst seviyede başarı göstereceğini ortaya koymuştur.")
        st.image(image5, caption="Endüstri 2.0  ")
    elif endustri_cesitleri == "Endüstri 3.0":
        st.write("Üçüncü Sanayi Devrimi, İkinci Dünya Savaşı sonrası başlayan ve 1970’li yıllardan sonra hız kazanan, üretimin sayısallaştığı, bilişim teknolojisi dönemi olarak da adlandırılır. Bununla birlikte, Üçüncü Sanayi Devrimi de benzer şekilde yeni bir enerji kaynağının kullanılmasıyla tetiklenen bir süreç olarak değerlendirilebilir. İkinci Dünya Savaşı’nı sona erdiren nükleer güç, devam eden yıllarda bir yıkım aracı olmaktan çıkarak bir enerji ham maddesi olarak ilgi görmüştür. Diğer yandan hesap makinesinden evrimleştirilen ve temelde yine ihtiyaç duyulan karmaşık hesapları yapma amacıyla geliştirilen “bilgisayarlar” da dönemin altyapısında önemli rol oynamıştır. Bilgisayarların işlem gücünün hızla artması akıllı makineleri doğururken, robotik endüstrinin ani ve çabuk atılım göstermesi, ilk kez üretimde insan gücünün azalmasına ve robot makinelerin insanların yerine üretimde daha fazla kullanılmasına neden olmuştur. Bu süreçte en temel kavram kuşkusuz ki bilgidir. Sosyal refahın artması ve yükselen eğitim seviyesi ile bilginin üretilmesi, yayılması ve toplumlar tarafından hızla kabul edilmesi, adına küreselleşme dediğimiz sanayi toplumundan bilgi toplumuna ilerleyen kültürel bir dönüşümü de sağlamıştır. Elektrik-elektronik teknolojisi alanı diğer tüm alanları geliştiren, temel ve üretken bir sanayiye dönüşürken, kendi tasarım ve teknolojilerini geliştirecek güce de ulaşmış durumda. Günümüzde baş döndürücü bir hıza ulaşan teknolojik gelişmelerin itici gücü olarak nitelendirilebilecek olan elektronik endüstrisi, mikroişlemci veya bilgisayar denetimli düzenleri gerçekleştirmesi ve televizyon, cep telefonu, kişisel bilgisayarlar gibi araçları gündelik hayata yerleştirmesi nedeniyle Üçüncü Sanayi Devrimi’nin baş aktörlerinden biri olarak gösterilebilir. Elektronik ve bilgisayar desteğinin sanayiye ve özellikle makine sektörüne entegre olması, 1969 yılında, algılayıcılardan aldığı bilgiyi kendine verilen programa göre işleyen ve iş elemanlarına aktaran mikroişlemci tabanlı bir cihaz olan ilk programlanabilir mantık devresinin (PLC) PLC Bedford, Massachusetts’te bir grup mühendis tarafından geliştirilmesiyle gerçekleşti. PLC’lerin üretim sistemlerinin otomatikleştirilmesine imkân vermesi sanayide yeni bir dönemi başlatırken, elektronik, bilgi ve iletişim teknolojilerinin gelişimi üretimin otomasyonunu sağladı. Dolayısıyla Birinci Sanayi Devrimi üretimin makineleşmesini, İkinci Sanayi Devrimi üretimin serileşmesini, Üçüncü Sanayi Devrimi ise üretimin otomasyonu ve sayısallaşmasını sağlamıştır.")
        st.image(image6, caption="Endüstri 3.0")
    elif endustri_cesitleri=="Endüstri 4.0":
        st.write("Endüstri 4.0 ya da 4. Sanayi Devrimi, birçok çağdaş otomasyon sistemini, veri alışverişlerini ve üretim teknolojilerini içeren ortak bir terimdir. Bu devrim nesnelerin interneti, internetin hizmetleri ve siber-fiziksel sistemlerden oluşan bir değerler bütünüdür. Aynı zamanda bu yapı akıllı üretim sisteminin oluşmasında büyük rol oynar. Bu devrim, üretim ortamında her bir verinin toplanmasına ve iyi bir şekilde izlenip analiz edilmesine olanak sağlayacağı için insan gözüyle verilerin toplanması ve geç kalınan karar süreçlerine göre daha verimli iş modelleri ortaya çıkaracaktır.İlk sanayi devrimi (1.0) su ve buhar gücünü kullanarak mekanik üretim sistemleri ile ortaya çıktı. İkinci sanayi devrimi (2.0) ile elektrik gücünün yardımıyla seri üretim tanıtılmıştı. Üçüncü sanayi devriminde (3.0) ise dijital devrim, elektroniklerin kullanımı ve BT (Bilgi Teknolojileri)'nin gelişmesiyle üretim daha da otomatikleştirildi. Dördüncü sanayi devrimi (4.0)'a gelinene kadar geçen tarihsel değişim aşağıdaki diyagramlarda özetlenmiştir.")
        st.image(image7, caption="Endüstri 1.0'dan 4.0'a Doğru")
        st.image(image8, caption="Endüstriyel Devrim")

#bulanık mantık sayfası
elif page == "Bulanık Mantık ":
    st.markdown("<h1 style='text-align:center;'> Bulanık Mantık </h1>", unsafe_allow_html=True)
    st.image(image3, width=700, caption="Bulanık Mantık")
    st.markdown("""\tBilimde klasik mantığa uyarlanmış matematiksel yaklaşım, keskin sınırları olan ve en rahat uygulanabilir bir yöntemdir. İhtiyaçlara uygun çözüm üretebilmek adına çeşitli sayıda matematiksel modeller oluşturulmuştur. Bu modeller düşüncenin, dilin, duyuların modellenebilmesi olanağına kapsayıcı yaklaşımda yeterli gelmemektedir. Doğada karşılaşılan zorluklar ve açmazlar, meydana gelen belirsizliklerin yeni metotlar ile modellenmesine kapı açmıştır. Bu metotların önde gelen alanlarından biri olan bulanık mantık kavramı, Aristotales mantığına aykırı olarak ortaya çıkmıştır.""")
    st.markdown("""\t[Bulanık mantık](https://dergipark.org.tr/tr/download/article-file/393211), insanların tecrübelerinden, verilerinden yararlanarak, elde ettiği değerleri belirli algoritmalar ile işleyip, oluşturacağı her bir kurala bağlı olarak belirli matematiksel fonksiyonların yardımı ile sonuç değerlerinin çıkarılmasıdır. Batı kültürde (Boolean) yani Aristonun ikili değer mantığı vardır. Bulanık mantık bu ikisi arasında değerleri de dikkate alarak çok değerli sonuçlar türetir ve büyüklükleri az, çok, biraz, orta, uzun, normal gibi sözel dile uygun değişkenler ile ifade eder. 0-1 değerleri yerine ara değerlerle (0.3, 0.92 gibi) işlem yapmaya olanak tanır. İki değerli üyeliği çok değerliliğe taşıyarak genelleme yeteneği katar (Ertunç, 2012).""")
#blokzinciri sayfası
elif page == "Blokzincir ":
    st.markdown("<h1 style='text-align:center;'> Blokzincir </h1>", unsafe_allow_html=True)
    st.markdown('<style>h1{color: black;}</style>', unsafe_allow_html=True)
    st.image(image9, width=700, caption="Blokzinciri")
    st.markdown("""[Blokzinciri](https://papers.ssrn.com/sol3/papers.cfm?abstract_id=2849251) 2008 yılında ortaya atılmış, 2009 yılında ise Bitcoin sanal para birimi ile birlikte tanınmaya başlamıştır.Bu teknoloji dağıtılmış bir kayıt defteri olarak tanımlanmaktadır. Daha kapsamlı bir ifadeyle Blokzinciri, dağıtık, paylaşılan, şifrelenmiş, geri dönüşü olmayan ve bozulmayan bir bilgi deposudur. Blokzinciri, ağ yardımı ile sistemi kullanan kullanıcılar arasındaki işlemlerin tümünü doğrulayarak saklayan bir sistemdir. Bu yüzden bütünlüğüne güvenilir bloklar ve bu blokları oluşturan sorgulanabilir işlemlerden oluşan bir veritabanı olarak tanımlanmaktadır.""")
    st.markdown("""[Blokzinciri](https://dergipark.org.tr/en/download/article-file/1081395) sisteminde işlemler bloklar halinde tutulur ve bu bloklar birbirine bağlanarak zincir oluşturulur. Belli kurallar çerçevesinde oluşturulan bloklar sisteme yazılmaktadır. Daha sonra blok tüm dağıtık kayıt defterlerine yayılır ve eklenir. Yeni blok oluşturmada bir önceki bloğa ait özet alınır ve ikinci blok üretilerek zincire ekleme yapılmaktadır. Bu yapı tüm blokları birbirine bağlayan ve bir önceki bloğun özeti ile beraber olacak biçimde devam eden bir yapı ile sürdürülür. Bir işlem gerçekleştiğinde mevcut ağ üzerinden yayınlanır ve şifreleme algoritmaları ile bu işlem doğrulanarak blok oluşturulur. Sisteme dahil olan her düğüm, sistemdeki herhangi iki kişi tarafından yapılan bu işlemi onaylayarak kaydını tutar. Bu sayede blok doğrulanır, sonrasında bu bilgi asla değiştirilemez veya silinemez. Her blok birbirine zincirlenerek eklenmeye devam eder. Böylece başka biri onları hiçbir zaman değiştiremez.""")
    st.image(image10, width=700, caption="Bloklar")
    st.markdown("""Sistemde bulunan her bir kullanıcı bir düğümü ifade eder. Sisteme katılan her düğüm, kendi başına bir blokzinciri kopyasına yan kayıt defterine bir başka deyişle veritabanına sahiptir. Bu defter bir uçtan uca protokolü kullanılarak diğer düğümlerle senkronize edilir. Bu sayede aracı ortadan kaldırılmakta ve merkezi bir otorite zorunluluğu da gerekmemektedir. Bir düğüm başarısız olur veya işlevini durdurursa, kalan düğümler arızalı yerin yokluğunda tüm işlem ayrıntılarını muhafaza eder. Bu şekilde sistem gerçek zamanlı bilgi sağlamakta ve işlemlerin hata ya da başarısızlık oranlarını [azaltmaktadır](https://d1wqtxts1xzle7.cloudfront.net/53539998/IRJET-V4I3711-with-cover-page-v2.pdf?Expires=1661536789&Signature=KHTxfcsOWJ5OPk767dp4Za8HmoMANYVhZ1yHbvOqZxs79kAs~h6Bv3FkPeczB4y3EPrpcGWlZiyp8hm6LiLH3x77l6Aq1oJjXhGhtj46Am~-VnBA5IWcfRp6wtfZnXDGfxuPniEtxVRTd-unv9Nm2SA1NJKSjjUdjxCJJv1N3-VruKJkEcJLsoQRlbysa3~nRUWgQHIu9fJgc07xYWCWGvqdZ6X5mNqMIicKIXpSyUMb4bJHC7conbeXmvC~okoQ-zgd~5y9bi1DOZG~dclPgO36AmwwQlZoEebQ44YFQhhbT1CskVXJZzMORJxLQYgF0H9Y33v8a92DyxxhdWW6-Q__&Key-Pair-Id=APKAJLOHF5GGSLRBV4ZA). """)
