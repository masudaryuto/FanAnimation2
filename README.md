# FanAnimation

<h2>基本設計</h2>
<p>https://drive.google.com/file/d/1RY4OQz33MvhjgOL9R_5P9RFpIxyvmRY2/view?usp=sharing</p>
<img width="200" alt="plan" src="https://user-images.githubusercontent.com/68851544/183114189-efd880ed-060e-406e-b2b1-00ac28e73a6d.png">

<img width="200" alt="plan" src="https://user-images.githubusercontent.com/68851544/183114250-e1835de7-5688-4cd5-8218-33866656129d.png">

<img width="200" alt="plan" src="https://user-images.githubusercontent.com/68851544/183114287-260c060d-82d5-47f6-967a-83d74e34ed72.png">

<img width="500" alt="plan" src="https://user-images.githubusercontent.com/68851544/183114307-7f882de0-f808-441f-aecc-423e1805dcf7.png">

<h2>詳細設計</h2>
<p>MVC(Model,View,Controller)のObserverパターン</p>
<img width="500" alt="plan" src="https://user-images.githubusercontent.com/68851544/184306296-30e4f934-d208-4c3f-a5ac-067abebd52a7.png">

<h2>テスト仕様書</h2>
<p>未定</p>

<h2>テスト結果</h2>
<p>MacBook Air(Retina,13-inch,2019)</p>
<table>
  <ul>
  <img width="200" alt="plan" src="https://user-images.githubusercontent.com/68851544/184308066-fb9031d8-16ba-48ae-b631-5f44c8e4efbc.jpg">
  </ul>
  <ul>
    <li>Processor: Intel Core i5 1.6GHz dual-core</li>
    <li>Retina display</li>
    <li>Memory: 8GB 2133MHz LPDDR3</li>
    <li>Graphics: Intel UHD Graphics 617</li>
    <li>Internal Solid State Drive: 256GB PCIe-based SSD</li>
    <li>Wireless 802.11ac Wi-Fi wireless networking; IEEE 802.11a/b/g/n compatible</li>
    <li>Bluetooth 4.2 wireless technology</li>
  </ul>
</table>

<h2>開発実績</h2>
<div><p>作成した言語は、C言語である。そして、「HandyGraphics」というライブラリを利用して簡単な扇風機アニメーションを作成した。</p>
<div>
  <img width="500" alt="plan" src="https://user-images.githubusercontent.com/68851544/183114307-7f882de0-f808-441f-aecc-423e1805dcf7.png">
  <p>計画通りに、アプリケーションの作成を行うことができた。</p>
  <p>1回生の時に作成した物であったため、改良するだけで済んだからであろう。</p>
  <p>大きな、バグは発生しないが、単体テストをこれから行なっていく必要があり、まだできていないため、品質保証としてはダメである。</p>
</div>

<h2>プログラム</h2>
<p>コードは、上記のソースコードである。</p>

<h2>マニュアル</h2>
<div>
  <p>最初に実行にあたり、「HandyGraphics」を導入しなければ、実行しない。実行したら、macOSの場合、Users/Applicationsにダウンロードした「HgDisplayer.app」を入れる。</p>
  <p>ダウンロードページ：http://www.cc.kyoto-su.ac.jp/~ogihara/Hg/</p>
  <br>
  <p>FanAnimation.appをダブルクリックまたは、ターミナル(bash,zsh)において「open FanAnimation.app」で起動する。</p>
  <p>起動しない場合、ターミナルにおいて、「xattr -r FanAnimation.app」として、拡張属性を外して実行してみる。</p>
  <p>また、「FanAnimation.app」が存在しない場合、FanAnimationディレクトリにおいて、make installを実行してみる。</p>
</div>

# LISENCE
  <p>作者：masudaryuto(Created:2022/08/12(Fri))</p>
  <p>許可：特になし</p>

# 参考文献
  <table>
    <ul>
      <li>Handy Graphicユーザーズガイド、http://www7a.biglobe.ne.jp/~ogihara/Hg/products/guide0.64.pdf</li>
      <ul>音楽と動画、背景画(引用)、フリー素材
        <li>夏の音：https://www.youtube.com/watch?v=C3rnW2EW788&t=52s</li>
        <li>扇風機とボタンの音：https://otologic.jp/free/se/cooling-heating01.html#google_vignette</li>
        <li>背景画：https://chicodeza.com/freeitems/enngawa-illust.html</li>
      </ul>
    </ul>

  </table>

  
