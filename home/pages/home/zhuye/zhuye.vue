<template>
	<view class="flex-col page">
	  <view style="padding: 20rpx 0; background-color: #f5f6f8; z-index: 100; box-sizing: border-box;">
	    <input
	      type="text"
	      v-model="searchText"
	      placeholder="请输入系列名称搜索"
	      style="width: calc(100% - 40rpx); padding: 20rpx 30rpx; border-radius: 40rpx; border: none; background-color: #f0f0f0; box-shadow: 0 2rpx 8rpx rgba(0,0,0,0.1); font-size: 28rpx; margin: 0 auto;"
	    />
	  </view>

	  <view v-if="!searchText" class="Souye_banner_box" style="margin: 20rpx 0; border-radius: 20rpx; overflow: hidden; box-shadow: 0 4rpx 12rpx rgba(0,0,0,0.1);">
	  	<swiper class="swiper" :indicator-dots="true" :autoplay="true" :interval="3000" :duration="1000" indicator-color="rgba(255,255,255,0.6)" indicator-active-color="#ffffff">
	  		<swiper-item @click.native="openSeries(seriesList[1])">
	  			<view class="swiper-item">
	  				<image class="banner" src="../../../static/kt1.png" mode="aspectFill"></image>
	  			</view>
	  		</swiper-item>
	  		<swiper-item @click.native="openSeries(seriesList[2])">
	  			<view class="swiper-item">
	  				<image class="banner" src="../../../static/kg1.jpg" mode="aspectFill"></image>
	  			</view>
	  		</swiper-item>
	  		<swiper-item @click.native="openSeries(seriesList[3])">
	  			<view class="swiper-item">
	  				<image class="banner" src="../../../static/ds1.png" mode="aspectFill"></image>
	  			</view>
	  		</swiper-item>
	  	</swiper>
	  </view>
	  
	  <view class="mt-22 flex-col">
	    <view
	      v-for="(item, idx) in filteredSeries"
	      :key="idx"
	      class="flex-col justify-start items-center relative group_2 view"
	      style="margin-bottom: 24rpx;"
	      @click="openSeries(item)"
	    >
	      <image :src="item.img" class="image_7" />
	      <text class="font text_2 pos_8">{{ item.name }}</text>
	    </view>
	  </view>
	  <view v-if="showPopup" class="popup-mask-full" @click.self="closePopup">
	    <view class="popup-content-full popup-slide-up">
	      <view class="popup-img-header-full" :style="popupImgStyle">
	        <view class="popup-header-gradient"></view>
	        <view class="popup-header-bottom-gradient"></view>
	        <view class="popup-header-bar">
	          <view class="popup-back-btn" @click.stop="closePopup">
	            <text class="popup-back-arrow">&#60;</text>
	          </view>
	          <text class="popup-header-title">{{ currentSeriesName }}</text>
	        </view>
	      </view>
	      <view class="popup-inner-card-full">
	        <component :is="currentSeriesComponent" />
	      </view>
	    </view>
	  </view>
	</view>
</template>

<script>
import DoorSeries from '@/pages/series/door.vue'
import AirSeries from '@/pages/series/air.vue'
import SwitchSeries from '@/pages/series/switch.vue'
import TvSeries from '@/pages/series/tv.vue'
export default {
	data() {
		return {
			searchText: '',
			seriesList: [
				{ name: '门系列', img: '../../../static/m1.png', key: 'door' },
				{ name: '空调系列', img: '../../../static/kt1.png', key: 'air' },
				{ name: '开关系列', img: '../../../static/kg1.jpg', key: 'switch' },
				{ name: '电视系列', img: '../../../static/ds1.png', key: 'tv' }
			],
			showPopup: false,
			currentSeries: null
		}
	},
	computed: {
		filteredSeries() {
			if (!this.searchText) return this.seriesList;
			return this.seriesList.filter(item =>
				item.name.includes(this.searchText)
			);
		},
		currentSeriesComponent() {
			switch (this.currentSeries) {
				case 'door': return 'DoorSeries';
				case 'air': return 'AirSeries';
				case 'switch': return 'SwitchSeries';
				case 'tv': return 'TvSeries';
				default: return null;
			}
		},
		currentSeriesName() {
			const series = this.seriesList.find(item => item.key === this.currentSeries);
			return series ? series.name : '';
		},
		popupImgStyle() {
			const series = this.seriesList.find(item => item.key === this.currentSeries);
			if (series) {
				return `background: url(${series.img}) center center / cover no-repeat;`;
			}
			return '';
		}
	},
	methods: {
		openSeries(series) {
			this.currentSeries = series.key;
			this.showPopup = true;
		},
		closePopup() {
			this.showPopup = false;
		}
	},
	components: {
		DoorSeries,
		AirSeries,
		SwitchSeries,
		TvSeries
	}
}
</script>

<style>
	/************************************************************
	** 请将全局样式拷贝到项目的全局 CSS 文件或者当前页面的顶部 **
	** 否则页面将无法正常显示                                  **
	************************************************************/
	
	html {
	  font-size: 16px;
	}
	
	body {
	  margin: 0;
	  font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', 'Roboto', 'Oxygen', 'Ubuntu', 'Cantarell', 'Fira Sans',
	    'Droid Sans', 'Helvetica Neue', 'Microsoft Yahei', sans-serif;
	  -webkit-font-smoothing: antialiased;
	  -moz-osx-font-smoothing: grayscale;
	}
	
	view,
	image,
	text {
	  box-sizing: border-box;
	  flex-shrink: 0;
	}
	
	#app {
	  width: 100vw;
	  height: 100vh;
	}
	
	.flex-row {
	  display: flex;
	  flex-direction: row;
	}
	
	.flex-col {
	  display: flex;
	  flex-direction: column;
	}
	
	.justify-start {
	  justify-content: flex-start;
	}
	
	.justify-end {
	  justify-content: flex-end;
	}
	
	.justify-center {
	  justify-content: center;
	}
	
	.justify-between {
	  justify-content: space-between;
	}
	
	.justify-around {
	  justify-content: space-around;
	}
	
	.justify-evenly {
	  justify-content: space-evenly;
	}
	
	.items-start {
	  align-items: flex-start;
	}
	
	.items-end {
	  align-items: flex-end;
	}
	
	.items-center {
	  align-items: center;
	}
	
	.items-baseline {
	  align-items: baseline;
	}
	
	.items-stretch {
	  align-items: stretch;
	}
	
	.self-start {
	  align-self: flex-start;
	}
	
	.self-end {
	  align-self: flex-end;
	}
	
	.self-center {
	  align-self: center;
	}
	
	.self-baseline {
	  align-self: baseline;
	}
	
	.self-stretch {
	  align-self: stretch;
	}
	
	.flex-1 {
	  flex: 1 1 0%;
	}
	
	.flex-auto {
	  flex: 1 1 auto;
	}
	
	.grow {
	  flex-grow: 1;
	}
	
	.grow-0 {
	  flex-grow: 0;
	}
	
	.shrink {
	  flex-shrink: 1;
	}
	
	.shrink-0 {
	  flex-shrink: 0;
	}
	
	.relative {
	  position: relative;
	}
	
	.ml-2 {
	  margin-left: 3rpx;
	}
	
	.mt-2 {
	  margin-top: 3rpx;
	}
	
	.ml-4 {
	  margin-left: 6rpx;
	}
	
	.mt-4 {
	  margin-top: 6rpx;
	}
	
	.ml-6 {
	  margin-left: 9rpx;
	}
	
	.mt-6 {
	  margin-top: 9rpx;
	}
	
	.ml-8 {
	  margin-left: 12rpx;
	}
	
	.mt-8 {
	  margin-top: 12rpx;
	}
	
	.ml-10 {
	  margin-left: 15rpx;
	}
	
	.mt-10 {
	  margin-top: 15rpx;
	}
	
	.ml-12 {
	  margin-left: 18rpx;
	}
	
	.mt-12 {
	  margin-top: 18rpx;
	}
	
	.ml-14 {
	  margin-left: 21rpx;
	}
	
	.mt-14 {
	  margin-top: 21rpx;
	}
	
	.ml-16 {
	  margin-left: 24rpx;
	}
	
	.mt-16 {
	  margin-top: 24rpx;
	}
	
	.ml-18 {
	  margin-left: 27rpx;
	}
	
	.mt-18 {
	  margin-top: 27rpx;
	}
	
	.ml-20 {
	  margin-left: 30rpx;
	}
	
	.mt-20 {
	  margin-top: 30rpx;
	}
	
	.ml-22 {
	  margin-left: 33rpx;
	}
	
	.mt-22 {
	  margin-top: 33rpx;
	}
	
	.ml-24 {
	  margin-left: 36rpx;
	}
	
	.mt-24 {
	  margin-top: 36rpx;
	}
	
	.ml-26 {
	  margin-left: 39rpx;
	}
	
	.mt-26 {
	  margin-top: 39rpx;
	}
	
	.ml-28 {
	  margin-left: 42rpx;
	}
	
	.mt-28 {
	  margin-top: 42rpx;
	}
	
	.ml-30 {
	  margin-left: 45rpx;
	}
	
	.mt-30 {
	  margin-top: 45rpx;
	}
	
	.ml-32 {
	  margin-left: 48rpx;
	}
	
	.mt-32 {
	  margin-top: 48rpx;
	}
	
	.ml-34 {
	  margin-left: 51rpx;
	}
	
	.mt-34 {
	  margin-top: 51rpx;
	}
	
	.ml-36 {
	  margin-left: 54rpx;
	}
	
	.mt-36 {
	  margin-top: 54rpx;
	}
	
	.ml-38 {
	  margin-left: 57rpx;
	}
	
	.mt-38 {
	  margin-top: 57rpx;
	}
	
	.ml-40 {
	  margin-left: 60rpx;
	}
	
	.mt-40 {
	  margin-top: 60rpx;
	}
	
	.ml-42 {
	  margin-left: 63rpx;
	}
	
	.mt-42 {
	  margin-top: 63rpx;
	}
	
	.ml-44 {
	  margin-left: 66rpx;
	}
	
	.mt-44 {
	  margin-top: 66rpx;
	}
	
	.ml-46 {
	  margin-left: 69rpx;
	}
	
	.mt-46 {
	  margin-top: 69rpx;
	}
	
	.ml-48 {
	  margin-left: 72rpx;
	}
	
	.mt-48 {
	  margin-top: 72rpx;
	}
	
	.ml-50 {
	  margin-left: 75rpx;
	}
	
	.mt-50 {
	  margin-top: 75rpx;
	}
	
	.ml-52 {
	  margin-left: 78rpx;
	}
	
	.mt-52 {
	  margin-top: 78rpx;
	}
	
	.ml-54 {
	  margin-left: 81rpx;
	}
	
	.mt-54 {
	  margin-top: 81rpx;
	}
	
	.ml-56 {
	  margin-left: 84rpx;
	}
	
	.mt-56 {
	  margin-top: 84rpx;
	}
	
	.ml-58 {
	  margin-left: 87rpx;
	}
	
	.mt-58 {
	  margin-top: 87rpx;
	}
	
	.ml-60 {
	  margin-left: 90rpx;
	}
	
	.mt-60 {
	  margin-top: 90rpx;
	}
	
	.ml-62 {
	  margin-left: 93rpx;
	}
	
	.mt-62 {
	  margin-top: 93rpx;
	}
	
	.ml-64 {
	  margin-left: 96rpx;
	}
	
	.mt-64 {
	  margin-top: 96rpx;
	}
	
	.ml-66 {
	  margin-left: 99rpx;
	}
	
	.mt-66 {
	  margin-top: 99rpx;
	}
	
	.ml-68 {
	  margin-left: 102rpx;
	}
	
	.mt-68 {
	  margin-top: 102rpx;
	}
	
	.ml-70 {
	  margin-left: 105rpx;
	}
	
	.mt-70 {
	  margin-top: 105rpx;
	}
	
	.ml-72 {
	  margin-left: 108rpx;
	}
	
	.mt-72 {
	  margin-top: 108rpx;
	}
	
	.ml-74 {
	  margin-left: 111rpx;
	}
	
	.mt-74 {
	  margin-top: 111rpx;
	}
	
	.ml-76 {
	  margin-left: 114rpx;
	}
	
	.mt-76 {
	  margin-top: 114rpx;
	}
	
	.ml-78 {
	  margin-left: 117rpx;
	}
	
	.mt-78 {
	  margin-top: 117rpx;
	}
	
	.ml-80 {
	  margin-left: 120rpx;
	}
	
	.mt-80 {
	  margin-top: 120rpx;
	}
	
	.ml-82 {
	  margin-left: 123rpx;
	}
	
	.mt-82 {
	  margin-top: 123rpx;
	}
	
	.ml-84 {
	  margin-left: 126rpx;
	}
	
	.mt-84 {
	  margin-top: 126rpx;
	}
	
	.ml-86 {
	  margin-left: 129rpx;
	}
	
	.mt-86 {
	  margin-top: 129rpx;
	}
	
	.ml-88 {
	  margin-left: 132rpx;
	}
	
	.mt-88 {
	  margin-top: 132rpx;
	}
	
	.ml-90 {
	  margin-left: 135rpx;
	}
	
	.mt-90 {
	  margin-top: 135rpx;
	}
	
	.ml-92 {
	  margin-left: 138rpx;
	}
	
	.mt-92 {
	  margin-top: 138rpx;
	}
	
	.ml-94 {
	  margin-left: 141rpx;
	}
	
	.mt-94 {
	  margin-top: 141rpx;
	}
	
	.ml-96 {
	  margin-left: 144rpx;
	}
	
	.mt-96 {
	  margin-top: 144rpx;
	}
	
	.ml-98 {
	  margin-left: 147rpx;
	}
	
	.mt-98 {
	  margin-top: 147rpx;
	}
	
	.ml-100 {
	  margin-left: 150rpx;
	}
	
	.mt-100 {
	  margin-top: 150rpx;
	}
	.mt-3 {
	  margin-top: 4.5rpx;
	}
	.mt-5 {
	  margin-top: 7.5rpx;
	}
	.page {
	  padding: 0 39rpx 54rpx;
	  background-color: #f5f6f8;
	  width: 100%;
	  overflow-y: auto;
	  overflow-x: hidden;
	  height: 100%;
	}
	.group {
	  padding-top: 33rpx;
	}
	.text {
	  color: #010000;
	  font-size: 40.01rpx;
	  font-family: SourceHanSansCN;
	  line-height: 48rpx;
	  width: 286.5rpx;
	}
	.image_6 {
	  margin-top: 18rpx;
	  width: 504rpx;
	  height: 121.5rpx;
	}
	.image-wrapper {
	  padding: 87rpx 0 18rpx;
	  background-image: url('https://ide.code.fun/api/image?token=6814f16bdefdb100111dda7c&name=1af6c85f432fd531574cbb0f31e68ce9.png');
	  background-size: 100% 100%;
	  background-repeat: no-repeat;
	  width: 162rpx;
	}
	.pos_2 {
	  position: absolute;
	  right: 78.5rpx;
	  top: 8.98rpx;
	}
	.image_5 {
	  width: 42rpx;
	  height: 61.99rpx;
	}
	.section {
	  padding: 18rpx 24rpx 0;
	  background-image: url('https://ide.code.fun/api/image?token=6814f16bdefdb100111dda7c&name=9f033560f15b4a34e3a4686aa6f45970.png');
	  background-size: 100% 100%;
	  background-repeat: no-repeat;
	  width: 181.5rpx;
	}
	.pos {
	  position: absolute;
	  right: 68.47rpx;
	  top: 0;
	}
	.image {
	  width: 24rpx;
	  height: 43.5rpx;
	}
	.section_3 {
	  margin-left: 45rpx;
	  background-color: #ffffff;
	  border-radius: 2rpx;
	  width: 12rpx;
	  height: 6rpx;
	}
	.image_3 {
	  border-radius: 7.98rpx;
	  width: 12rpx;
	  height: 74rpx;
	}
	.pos_5 {
	  position: absolute;
	  right: 153rpx;
	  top: 56.98rpx;
	}
	.section_4 {
	  background-color: #010000;
	  border-radius: 50%;
	  width: 28.01rpx;
	  height: 28.01rpx;
	}
	.pos_7 {
	  position: absolute;
	  right: 145rpx;
	  top: 124.98rpx;
	}
	.image_2 {
	  width: 46.5rpx;
	  height: 43.98rpx;
	}
	.pos_4 {
	  position: absolute;
	  right: 40.48rpx;
	  top: 42.99rpx;
	}
	.image_4 {
	  border-radius: 7.98rpx;
	  width: 54rpx;
	  height: 92rpx;
	}
	.pos_6 {
	  position: absolute;
	  right: 51rpx;
	  bottom: 45.73rpx;
	}
	.section_2 {
	  background-color: #010000;
	  border-radius: 2rpx;
	  width: 31.99rpx;
	  height: 12rpx;
	}
	.pos_3 {
	  position: absolute;
	  right: 199rpx;
	  top: 8.98rpx;
	}
	.group_2 {
	  filter: drop-shadow(0rpx 3rpx 3rpx #00000040);
	}
	.view {
	  margin-left: 3rpx;
	  margin-right: 9rpx;
	}
	.image_7 {
	  border-radius: 22.5rpx;
	  filter: drop-shadow(0rpx 3rpx 3rpx #00000040);
	  backdrop-filter: blur(3rpx);
	  width: 658.5rpx;
	  height: 283.5rpx;
	}
	.font {
	  font-size: 36rpx;
	  font-family: SourceHanSansCN;
	  line-height: 43.5rpx;
	  color: #ffffff;
	}
	.text_2 {
	  width: 33rpx;
	}
	.pos_8 {
	  position: absolute;
	  right: 79.09rpx;
	  top: 50%;
	  transform: translateY(-50%);
	}
	.section_5 {
	  margin: 30rpx 6rpx 0 3rpx;
	  filter: drop-shadow(0rpx 3rpx 3rpx #00000040);
	  border-radius: 22.5rpx;
	  background-image: url('https://ide.code.fun/api/image?token=6814f16bdefdb100111dda7c&name=47f81131ce2fd159c1fe6bbc780a67f0.png');
	  background-size: 100% 100%;
	  background-repeat: no-repeat;
	}
	.section_6 {
	  border-radius: 22.5rpx;
	  background-image: url('https://ide.code.fun/api/image?token=6814f16bdefdb100111dda7c&name=47f81131ce2fd159c1fe6bbc780a67f0.png');
	  background-size: 100% 100%;
	  background-repeat: no-repeat;
	  height: 283.5rpx;
	}
	.pos_9 {
	  position: absolute;
	  right: 86.95rpx;
	  top: 50%;
	  transform: translateY(-50%);
	}
	.section_7 {
	  margin-top: 36rpx;
	  filter: drop-shadow(0rpx 3rpx 3rpx #00000040);
	  border-radius: 22.5rpx;
	  background-image: url('https://ide.code.fun/api/image?token=6814f16bdefdb100111dda7c&name=85d366947945c4e9b8df461d539f9c90.png');
	  background-size: 100% 100%;
	  background-repeat: no-repeat;
	}
	.section_8 {
	  border-radius: 22.5rpx;
	  background-image: url('https://ide.code.fun/api/image?token=6814f16bdefdb100111dda7c&name=85d366947945c4e9b8df461d539f9c90.png');
	  background-size: 100% 100%;
	  background-repeat: no-repeat;
	  height: 283.5rpx;
	}
	.text_3 {
	  color: #000000;
	}
	.pos_10 {
	  position: absolute;
	  right: 83.23rpx;
	  top: 50%;
	  transform: translateY(-50%);
	}
	.view_2 {
	  margin-top: 33rpx;
	}
	.image_8 {
	  border-radius: 22.5rpx;
	  width: 670.5rpx;
	  height: 283.5rpx;
	}
	.text_4 {
	  width: 34.5rpx;
	}
	.pos_11 {
	  position: absolute;
	  right: 84.11rpx;
	  top: 50%;
	  transform: translateY(-50%);
	}
	.Souye_banner_box {
	  width: 100%;
	  height: 300rpx;
	}
	
	.swiper {
	  width: 100%;
	  height: 100%;
	}
	
	.swiper-item {
	  width: 100%;
	  height: 100%;
	}
	
	.banner {
	  width: 100%;
	  height: 100%;
	  border-radius: 20rpx;
	}
	.popup-mask-full {
	  position: fixed;
	  left: 0;
	  right: 0;
	  top: 0;
	  bottom: 0;
	  z-index: 9999;
	  display: flex;
	  flex-direction: column;
	  align-items: stretch;
	  justify-content: flex-end;
	  background: #fff;
	}
	.popup-content-full {
	  width: 100vw;
	  height: 100vh;
	  background: #fff;
	  display: flex;
	  flex-direction: column;
	  align-items: stretch;
	  animation: popup-slide-up 0.35s cubic-bezier(0.4,0,0.2,1);
	}
	.popup-img-header-full {
	  width: 100vw;
	  height: 280rpx;
	  min-height: 180rpx;
	  background-size: cover;
	  background-position: center;
	  position: relative;
	  display: flex;
	  align-items: flex-start;
	  justify-content: flex-start;
	  overflow: hidden;
	  border-bottom-left-radius: 36rpx;
	  border-bottom-right-radius: 36rpx;
	  margin-bottom: 0;
	}
	.popup-header-gradient {
	  position: absolute;
	  left: 0;
	  top: 0;
	  width: 100%;
	  height: 120rpx;
	  background: linear-gradient(to bottom, rgba(0,0,0,0.38), rgba(0,0,0,0.08) 80%, transparent 100%);
	  z-index: 1;
	  pointer-events: none;
	}
	.popup-header-bottom-gradient {
	  position: absolute;
	  left: 0;
	  right: 0;
	  bottom: 0;
	  height: 48rpx;
	  border-bottom-left-radius: 36rpx;
	  border-bottom-right-radius: 36rpx;
	  background: linear-gradient(to bottom, rgba(255,255,255,0) 0%, #fff 100%);
	  z-index: 2;
	  pointer-events: none;
	}
	.popup-header-bar {
	  width: 100%;
	  display: flex;
	  flex-direction: row;
	  align-items: center;
	  padding: 36rpx 0 0 24rpx;
	  position: absolute;
	  left: 0;
	  top: 0;
	  z-index: 2;
	}
	.popup-back-btn {
	  width: 60rpx;
	  height: 60rpx;
	  display: flex;
	  align-items: center;
	  justify-content: center;
	  border-radius: 50%;
	  background: rgba(0,0,0,0.22);
	  margin-right: 18rpx;
	  box-shadow: 0 2rpx 8rpx rgba(0,0,0,0.18);
	  transition: background 0.2s, box-shadow 0.2s, transform 0.1s;
	}
	.popup-back-btn:active {
	  background: rgba(0,0,0,0.32);
	  box-shadow: 0 4rpx 16rpx rgba(0,0,0,0.22);
	  transform: scale(0.92);
	}
	.popup-back-arrow {
	  font-size: 40rpx;
	  color: #fff;
	  font-weight: bold;
	  text-shadow: 0 2rpx 8rpx rgba(0,0,0,0.18);
	}
	.popup-header-title {
	  font-size: 38rpx;
	  color: #fff;
	  font-weight: 700;
	  letter-spacing: 2rpx;
	  text-shadow: 0 4rpx 16rpx rgba(0,0,0,0.22);
	}
	.popup-inner-card-full {
	  flex: 1;
	  width: 100vw;
	  background: #fff;
	  border-top-left-radius: 36rpx;
	  border-top-right-radius: 36rpx;
	  box-shadow: 0 -8rpx 32rpx rgba(0,0,0,0.10);
	  padding: 56rpx 0 0 0;
	  display: flex;
	  flex-direction: column;
	  align-items: center;
	  overflow-y: auto;
	  z-index: 2;
	  margin-top: -36rpx;
	}
	@keyframes popup-slide-up {
	  from { transform: translateY(100%); }
	  to { transform: translateY(0); }
	}
</style>
