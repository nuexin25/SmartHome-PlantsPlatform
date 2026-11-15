<template>
	<view class="control-bg">
		<!-- 温湿度卡片 -->
		<view class="card th-card">
			<view class="th-icon-group">
				<view class="th-icon-block">
					<text class="th-icon">🌡️</text>
					<text class="th-num">{{temp}}°C</text>
				</view>
				<view class="th-icon-block">
					<text class="th-icon">💧</text>
					<text class="th-num">{{humi}}%</text>
				</view>
			</view>
			<view class="th-label-row">
				<text class="th-label">温度</text>
				<text class="th-label">湿度</text>
			</view>
		</view>

		<!-- 设备卡片 -->
		<view class="device-cards">
			<view class="card device-card">
				<view class="device-left">
					<text class="device-icon">🚪</text>
					<text class="device-name">门</text>
				</view>
				<switch :checked="doorOn" @change="onMenSwitch" color="#000" />
			</view>
			<view class="card device-card">
				<view class="device-left">
					<text class="device-icon">❄️</text>
					<text class="device-name">空调</text>
				</view>
				<switch :checked="acOn" @change="onFanSwitch" color="#000" />
			</view>
			<view class="card device-card">
				<view class="device-left">
					<text class="device-icon">💡</text>
					<text class="device-name">灯</text>
				</view>
				<switch :checked="lightOn" @change="onLedSwitch" color="#000" />
			</view>
		</view>
	</view>
</template>

<script>
	const{createCommonToken} = require('@/key.js')
	export default {
		data() {
			return {
				temp:'',
				humi:'',
				led:false,
				men:false,
				fan:false,
				token:'',
			}
		},
		onLoad() {
			const params ={ 
			author_key:'VTmVl547ApZa5O8h8xyxMkvQ0P3ima8BGox7eBSh7mwT9WGsWa9uVW2CDEmsTEJmfcUuUaZIRpmE4vaJwbniQg==',
			version:'2022-05-01',
			user_id:'375185',
			}
			this.token = createCommonToken(params);
		},
		onShow(){
			this.fetchDevData();
			setInterval(()=>{
				this.fetchDevData();
			},3000)
		},
		methods: {
			fetchDevData(){
				uni.request({
					url: 'https://iot-api.heclouds.com/thingmodel/query-device-property', 
					   method:'GET',
						data: {
							product_id: '38R6xQeaZk',
							device_name: 'a1'
					    },
					    header: {
					        'authorization': this.token //自定义请求头信息
					    },
					    success: (res) => {
						console.log(res.data);
					    console.log(res.data.data[1].value);
						this.humi = res.data.data[1].value;
						this.temp = res.data.data[4].value;
						this.led =res.data.data[2].value ==='false';
						this.men =res.data.data[3].value ==='false';
						this.fan =res.data.data[0].value ==='false';
					}
				});
			},
			onLedSwitch(event){
				
				let value = event.detail.value;
				uni.request({
					url: 'https://iot-api.heclouds.com/thingmodel/set-device-property', 
					   method:'POST',
						data: {
							product_id: '38R6xQeaZk',
							device_name: 'a1',
							params:{"led":value}
					    },
					    header: {
					        'authorization': this.token //自定义请求头信息
					    },
					   
				});
			},
			onMenSwitch(event){
				let value = event.detail.value;
				uni.request({
					url: 'https://iot-api.heclouds.com/thingmodel/set-device-property', 
					   method:'POST',
						data: {
							product_id: '38R6xQeaZk',
							device_name: 'a1',
							params:{"men":value}
					    },
					    header: {
					        'authorization': this.token //自定义请求头信息
					    },
					    success: () => {
						console.log();
					}
				});
			},
			onFanSwitch(event){
				let value = event.detail.value;
				uni.request({
					url: 'https://iot-api.heclouds.com/thingmodel/set-device-property', 
					   method:'POST',
						data: {
							product_id: '38R6xQeaZk',
							device_name: 'a1',
							params:{"fan":value}
					    },
					    header: {
					        'authorization': this.token //自定义请求头信息
					    },
					    success: () => {
						console.log();
					}
				});
			},
			

		}
	}
</script>

<style scoped>
	.control-bg {
		min-height: 100vh;
		background: #f6f7fa;
		padding: 32rpx 0 0 0;
		display: flex;
		flex-direction: column;
		align-items: center;
	}

	.card {
		background: #fff;
		border-radius: 24rpx;
		box-shadow: 0 4rpx 24rpx rgba(0,0,0,0.06);
		margin-bottom: 32rpx;
		padding: 32rpx 24rpx;
	}

	.th-card {
		width: 85vw;
		margin-top: 32rpx;
		display: flex;
		flex-direction: column;
		align-items: center;
	}

	.th-icon-group {
		display: flex;
		flex-direction: row;
		justify-content: space-between;
		width: 100%;
		margin-bottom: 12rpx;
	}

	.th-icon-block {
		display: flex;
		flex-direction: column;
		align-items: center;
		flex: 1;
	}

	.th-icon {
		font-size: 48rpx;
		margin-bottom: 8rpx;
	}

	.th-num {
		font-size: 40rpx;
		font-weight: bold;
		color: #222;
	}

	.th-label-row {
		display: flex;
		flex-direction: row;
		justify-content: space-between;
		width: 100%;
		margin-top: 4rpx;
	}

	.th-label {
		flex: 1;
		text-align: center;
		font-size: 26rpx;
		color: #888;
	}

	.device-cards {
		width: 85vw;
		display: flex;
		flex-direction: column;
		gap: 24rpx;
		margin-top: 16rpx;
	}

	.device-card {
		display: flex;
		flex-direction: row;
		align-items: center;
		justify-content: space-between;
		padding: 28rpx 24rpx;
	}

	.device-left {
		display: flex;
		flex-direction: row;
		align-items: center;
	}

	.device-icon {
		font-size: 40rpx;
		margin-right: 18rpx;
	}

	.device-name {
		font-size: 32rpx;
		color: #222;
		font-weight: 500;
	}
</style>